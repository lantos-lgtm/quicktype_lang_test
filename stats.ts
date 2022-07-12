// To parse this data:
//
//   import { Convert, Stats } from "./file";
//
//   const stats = Convert.toStats(json);
//
// These functions will throw an error if the JSON doesn't
// match the expected interface, even if the JSON is valid.

export interface Stats {
    read:          Date;
    preread:       Date;
    pids_stats:    PidsStats;
    blkio_stats:   BlkioStats;
    num_procs:     number;
    storage_stats: StorageStats;
    cpu_stats:     CPUStats;
    precpu_stats:  PrecpuStats;
    memory_stats:  MemoryStats;
    name:          string;
    id:            string;
    networks:      Networks;
}

export interface BlkioStats {
    io_service_bytes_recursive: IoServiceBytesRecursive[];
    io_serviced_recursive:      null;
    io_queue_recursive:         null;
    io_service_time_recursive:  null;
    io_wait_time_recursive:     null;
    io_merged_recursive:        null;
    io_time_recursive:          null;
    sectors_recursive:          null;
}

export interface IoServiceBytesRecursive {
    major: number;
    minor: number;
    op:    string;
    value: number;
}

export interface CPUStats {
    cpu_usage:        CPUUsage;
    system_cpu_usage: number;
    online_cpus:      number;
    throttling_data:  ThrottlingData;
}

export interface CPUUsage {
    total_usage:         number;
    usage_in_kernelmode: number;
    usage_in_usermode:   number;
}

export interface ThrottlingData {
    periods:           number;
    throttled_periods: number;
    throttled_time:    number;
}

export interface MemoryStats {
    usage: number;
    stats: { [key: string]: number };
    limit: number;
}

export interface Networks {
    eth0: Eth0;
}

export interface Eth0 {
    rx_bytes:   number;
    rx_packets: number;
    rx_errors:  number;
    rx_dropped: number;
    tx_bytes:   number;
    tx_packets: number;
    tx_errors:  number;
    tx_dropped: number;
}

export interface PidsStats {
    current: number;
    limit:   number;
}

export interface PrecpuStats {
    cpu_usage:       CPUUsage;
    throttling_data: ThrottlingData;
}

export interface StorageStats {
}

// Converts JSON strings to/from your types
// and asserts the results of JSON.parse at runtime
export class Convert {
    public static toStats(json: string): Stats {
        return cast(JSON.parse(json), r("Stats"));
    }

    public static statsToJson(value: Stats): string {
        return JSON.stringify(uncast(value, r("Stats")), null, 2);
    }
}

function invalidValue(typ: any, val: any, key: any = ''): never {
    if (key) {
        throw Error(`Invalid value for key "${key}". Expected type ${JSON.stringify(typ)} but got ${JSON.stringify(val)}`);
    }
    throw Error(`Invalid value ${JSON.stringify(val)} for type ${JSON.stringify(typ)}`, );
}

function jsonToJSProps(typ: any): any {
    if (typ.jsonToJS === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.json] = { key: p.js, typ: p.typ });
        typ.jsonToJS = map;
    }
    return typ.jsonToJS;
}

function jsToJSONProps(typ: any): any {
    if (typ.jsToJSON === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.js] = { key: p.json, typ: p.typ });
        typ.jsToJSON = map;
    }
    return typ.jsToJSON;
}

function transform(val: any, typ: any, getProps: any, key: any = ''): any {
    function transformPrimitive(typ: string, val: any): any {
        if (typeof typ === typeof val) return val;
        return invalidValue(typ, val, key);
    }

    function transformUnion(typs: any[], val: any): any {
        // val must validate against one typ in typs
        const l = typs.length;
        for (let i = 0; i < l; i++) {
            const typ = typs[i];
            try {
                return transform(val, typ, getProps);
            } catch (_) {}
        }
        return invalidValue(typs, val);
    }

    function transformEnum(cases: string[], val: any): any {
        if (cases.indexOf(val) !== -1) return val;
        return invalidValue(cases, val);
    }

    function transformArray(typ: any, val: any): any {
        // val must be an array with no invalid elements
        if (!Array.isArray(val)) return invalidValue("array", val);
        return val.map(el => transform(el, typ, getProps));
    }

    function transformDate(val: any): any {
        if (val === null) {
            return null;
        }
        const d = new Date(val);
        if (isNaN(d.valueOf())) {
            return invalidValue("Date", val);
        }
        return d;
    }

    function transformObject(props: { [k: string]: any }, additional: any, val: any): any {
        if (val === null || typeof val !== "object" || Array.isArray(val)) {
            return invalidValue("object", val);
        }
        const result: any = {};
        Object.getOwnPropertyNames(props).forEach(key => {
            const prop = props[key];
            const v = Object.prototype.hasOwnProperty.call(val, key) ? val[key] : undefined;
            result[prop.key] = transform(v, prop.typ, getProps, prop.key);
        });
        Object.getOwnPropertyNames(val).forEach(key => {
            if (!Object.prototype.hasOwnProperty.call(props, key)) {
                result[key] = transform(val[key], additional, getProps, key);
            }
        });
        return result;
    }

    if (typ === "any") return val;
    if (typ === null) {
        if (val === null) return val;
        return invalidValue(typ, val);
    }
    if (typ === false) return invalidValue(typ, val);
    while (typeof typ === "object" && typ.ref !== undefined) {
        typ = typeMap[typ.ref];
    }
    if (Array.isArray(typ)) return transformEnum(typ, val);
    if (typeof typ === "object") {
        return typ.hasOwnProperty("unionMembers") ? transformUnion(typ.unionMembers, val)
            : typ.hasOwnProperty("arrayItems")    ? transformArray(typ.arrayItems, val)
            : typ.hasOwnProperty("props")         ? transformObject(getProps(typ), typ.additional, val)
            : invalidValue(typ, val);
    }
    // Numbers can be parsed by Date but shouldn't be.
    if (typ === Date && typeof val !== "number") return transformDate(val);
    return transformPrimitive(typ, val);
}

function cast<T>(val: any, typ: any): T {
    return transform(val, typ, jsonToJSProps);
}

function uncast<T>(val: T, typ: any): any {
    return transform(val, typ, jsToJSONProps);
}

function a(typ: any) {
    return { arrayItems: typ };
}

function u(...typs: any[]) {
    return { unionMembers: typs };
}

function o(props: any[], additional: any) {
    return { props, additional };
}

function m(additional: any) {
    return { props: [], additional };
}

function r(name: string) {
    return { ref: name };
}

const typeMap: any = {
    "Stats": o([
        { json: "read", js: "read", typ: Date },
        { json: "preread", js: "preread", typ: Date },
        { json: "pids_stats", js: "pids_stats", typ: r("PidsStats") },
        { json: "blkio_stats", js: "blkio_stats", typ: r("BlkioStats") },
        { json: "num_procs", js: "num_procs", typ: 0 },
        { json: "storage_stats", js: "storage_stats", typ: r("StorageStats") },
        { json: "cpu_stats", js: "cpu_stats", typ: r("CPUStats") },
        { json: "precpu_stats", js: "precpu_stats", typ: r("PrecpuStats") },
        { json: "memory_stats", js: "memory_stats", typ: r("MemoryStats") },
        { json: "name", js: "name", typ: "" },
        { json: "id", js: "id", typ: "" },
        { json: "networks", js: "networks", typ: r("Networks") },
    ], false),
    "BlkioStats": o([
        { json: "io_service_bytes_recursive", js: "io_service_bytes_recursive", typ: a(r("IoServiceBytesRecursive")) },
        { json: "io_serviced_recursive", js: "io_serviced_recursive", typ: null },
        { json: "io_queue_recursive", js: "io_queue_recursive", typ: null },
        { json: "io_service_time_recursive", js: "io_service_time_recursive", typ: null },
        { json: "io_wait_time_recursive", js: "io_wait_time_recursive", typ: null },
        { json: "io_merged_recursive", js: "io_merged_recursive", typ: null },
        { json: "io_time_recursive", js: "io_time_recursive", typ: null },
        { json: "sectors_recursive", js: "sectors_recursive", typ: null },
    ], false),
    "IoServiceBytesRecursive": o([
        { json: "major", js: "major", typ: 0 },
        { json: "minor", js: "minor", typ: 0 },
        { json: "op", js: "op", typ: "" },
        { json: "value", js: "value", typ: 0 },
    ], false),
    "CPUStats": o([
        { json: "cpu_usage", js: "cpu_usage", typ: r("CPUUsage") },
        { json: "system_cpu_usage", js: "system_cpu_usage", typ: 0 },
        { json: "online_cpus", js: "online_cpus", typ: 0 },
        { json: "throttling_data", js: "throttling_data", typ: r("ThrottlingData") },
    ], false),
    "CPUUsage": o([
        { json: "total_usage", js: "total_usage", typ: 0 },
        { json: "usage_in_kernelmode", js: "usage_in_kernelmode", typ: 0 },
        { json: "usage_in_usermode", js: "usage_in_usermode", typ: 0 },
    ], false),
    "ThrottlingData": o([
        { json: "periods", js: "periods", typ: 0 },
        { json: "throttled_periods", js: "throttled_periods", typ: 0 },
        { json: "throttled_time", js: "throttled_time", typ: 0 },
    ], false),
    "MemoryStats": o([
        { json: "usage", js: "usage", typ: 0 },
        { json: "stats", js: "stats", typ: m(0) },
        { json: "limit", js: "limit", typ: 0 },
    ], false),
    "Networks": o([
        { json: "eth0", js: "eth0", typ: r("Eth0") },
    ], false),
    "Eth0": o([
        { json: "rx_bytes", js: "rx_bytes", typ: 0 },
        { json: "rx_packets", js: "rx_packets", typ: 0 },
        { json: "rx_errors", js: "rx_errors", typ: 0 },
        { json: "rx_dropped", js: "rx_dropped", typ: 0 },
        { json: "tx_bytes", js: "tx_bytes", typ: 0 },
        { json: "tx_packets", js: "tx_packets", typ: 0 },
        { json: "tx_errors", js: "tx_errors", typ: 0 },
        { json: "tx_dropped", js: "tx_dropped", typ: 0 },
    ], false),
    "PidsStats": o([
        { json: "current", js: "current", typ: 0 },
        { json: "limit", js: "limit", typ: 0 },
    ], false),
    "PrecpuStats": o([
        { json: "cpu_usage", js: "cpu_usage", typ: r("CPUUsage") },
        { json: "throttling_data", js: "throttling_data", typ: r("ThrottlingData") },
    ], false),
    "StorageStats": o([
    ], false),
};

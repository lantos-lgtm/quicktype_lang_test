# This code parses date/times, so please
#
#     pip install python-dateutil
#
# To use this code, make sure you
#
#     import json
#
# and then, to convert JSON from a string, do
#
#     result = stats_from_dict(json.loads(json_string))

from typing import Any, List, Dict, TypeVar, Callable, Type, cast
from datetime import datetime
import dateutil.parser


T = TypeVar("T")


def from_int(x: Any) -> int:
    assert isinstance(x, int) and not isinstance(x, bool)
    return x


def from_str(x: Any) -> str:
    assert isinstance(x, str)
    return x


def from_list(f: Callable[[Any], T], x: Any) -> List[T]:
    assert isinstance(x, list)
    return [f(y) for y in x]


def from_none(x: Any) -> Any:
    assert x is None
    return x


def to_class(c: Type[T], x: Any) -> dict:
    assert isinstance(x, c)
    return cast(Any, x).to_dict()


def from_dict(f: Callable[[Any], T], x: Any) -> Dict[str, T]:
    assert isinstance(x, dict)
    return { k: f(v) for (k, v) in x.items() }


def from_datetime(x: Any) -> datetime:
    return dateutil.parser.parse(x)


class IoServiceBytesRecursive:
    major: int
    minor: int
    op: str
    value: int

    def __init__(self, major: int, minor: int, op: str, value: int) -> None:
        self.major = major
        self.minor = minor
        self.op = op
        self.value = value

    @staticmethod
    def from_dict(obj: Any) -> 'IoServiceBytesRecursive':
        assert isinstance(obj, dict)
        major = from_int(obj.get("major"))
        minor = from_int(obj.get("minor"))
        op = from_str(obj.get("op"))
        value = from_int(obj.get("value"))
        return IoServiceBytesRecursive(major, minor, op, value)

    def to_dict(self) -> dict:
        result: dict = {}
        result["major"] = from_int(self.major)
        result["minor"] = from_int(self.minor)
        result["op"] = from_str(self.op)
        result["value"] = from_int(self.value)
        return result


class BlkioStats:
    io_service_bytes_recursive: List[IoServiceBytesRecursive]
    io_serviced_recursive: None
    io_queue_recursive: None
    io_service_time_recursive: None
    io_wait_time_recursive: None
    io_merged_recursive: None
    io_time_recursive: None
    sectors_recursive: None

    def __init__(self, io_service_bytes_recursive: List[IoServiceBytesRecursive], io_serviced_recursive: None, io_queue_recursive: None, io_service_time_recursive: None, io_wait_time_recursive: None, io_merged_recursive: None, io_time_recursive: None, sectors_recursive: None) -> None:
        self.io_service_bytes_recursive = io_service_bytes_recursive
        self.io_serviced_recursive = io_serviced_recursive
        self.io_queue_recursive = io_queue_recursive
        self.io_service_time_recursive = io_service_time_recursive
        self.io_wait_time_recursive = io_wait_time_recursive
        self.io_merged_recursive = io_merged_recursive
        self.io_time_recursive = io_time_recursive
        self.sectors_recursive = sectors_recursive

    @staticmethod
    def from_dict(obj: Any) -> 'BlkioStats':
        assert isinstance(obj, dict)
        io_service_bytes_recursive = from_list(IoServiceBytesRecursive.from_dict, obj.get("io_service_bytes_recursive"))
        io_serviced_recursive = from_none(obj.get("io_serviced_recursive"))
        io_queue_recursive = from_none(obj.get("io_queue_recursive"))
        io_service_time_recursive = from_none(obj.get("io_service_time_recursive"))
        io_wait_time_recursive = from_none(obj.get("io_wait_time_recursive"))
        io_merged_recursive = from_none(obj.get("io_merged_recursive"))
        io_time_recursive = from_none(obj.get("io_time_recursive"))
        sectors_recursive = from_none(obj.get("sectors_recursive"))
        return BlkioStats(io_service_bytes_recursive, io_serviced_recursive, io_queue_recursive, io_service_time_recursive, io_wait_time_recursive, io_merged_recursive, io_time_recursive, sectors_recursive)

    def to_dict(self) -> dict:
        result: dict = {}
        result["io_service_bytes_recursive"] = from_list(lambda x: to_class(IoServiceBytesRecursive, x), self.io_service_bytes_recursive)
        result["io_serviced_recursive"] = from_none(self.io_serviced_recursive)
        result["io_queue_recursive"] = from_none(self.io_queue_recursive)
        result["io_service_time_recursive"] = from_none(self.io_service_time_recursive)
        result["io_wait_time_recursive"] = from_none(self.io_wait_time_recursive)
        result["io_merged_recursive"] = from_none(self.io_merged_recursive)
        result["io_time_recursive"] = from_none(self.io_time_recursive)
        result["sectors_recursive"] = from_none(self.sectors_recursive)
        return result


class CPUUsage:
    total_usage: int
    usage_in_kernelmode: int
    usage_in_usermode: int

    def __init__(self, total_usage: int, usage_in_kernelmode: int, usage_in_usermode: int) -> None:
        self.total_usage = total_usage
        self.usage_in_kernelmode = usage_in_kernelmode
        self.usage_in_usermode = usage_in_usermode

    @staticmethod
    def from_dict(obj: Any) -> 'CPUUsage':
        assert isinstance(obj, dict)
        total_usage = from_int(obj.get("total_usage"))
        usage_in_kernelmode = from_int(obj.get("usage_in_kernelmode"))
        usage_in_usermode = from_int(obj.get("usage_in_usermode"))
        return CPUUsage(total_usage, usage_in_kernelmode, usage_in_usermode)

    def to_dict(self) -> dict:
        result: dict = {}
        result["total_usage"] = from_int(self.total_usage)
        result["usage_in_kernelmode"] = from_int(self.usage_in_kernelmode)
        result["usage_in_usermode"] = from_int(self.usage_in_usermode)
        return result


class ThrottlingData:
    periods: int
    throttled_periods: int
    throttled_time: int

    def __init__(self, periods: int, throttled_periods: int, throttled_time: int) -> None:
        self.periods = periods
        self.throttled_periods = throttled_periods
        self.throttled_time = throttled_time

    @staticmethod
    def from_dict(obj: Any) -> 'ThrottlingData':
        assert isinstance(obj, dict)
        periods = from_int(obj.get("periods"))
        throttled_periods = from_int(obj.get("throttled_periods"))
        throttled_time = from_int(obj.get("throttled_time"))
        return ThrottlingData(periods, throttled_periods, throttled_time)

    def to_dict(self) -> dict:
        result: dict = {}
        result["periods"] = from_int(self.periods)
        result["throttled_periods"] = from_int(self.throttled_periods)
        result["throttled_time"] = from_int(self.throttled_time)
        return result


class CPUStats:
    cpu_usage: CPUUsage
    system_cpu_usage: int
    online_cpus: int
    throttling_data: ThrottlingData

    def __init__(self, cpu_usage: CPUUsage, system_cpu_usage: int, online_cpus: int, throttling_data: ThrottlingData) -> None:
        self.cpu_usage = cpu_usage
        self.system_cpu_usage = system_cpu_usage
        self.online_cpus = online_cpus
        self.throttling_data = throttling_data

    @staticmethod
    def from_dict(obj: Any) -> 'CPUStats':
        assert isinstance(obj, dict)
        cpu_usage = CPUUsage.from_dict(obj.get("cpu_usage"))
        system_cpu_usage = from_int(obj.get("system_cpu_usage"))
        online_cpus = from_int(obj.get("online_cpus"))
        throttling_data = ThrottlingData.from_dict(obj.get("throttling_data"))
        return CPUStats(cpu_usage, system_cpu_usage, online_cpus, throttling_data)

    def to_dict(self) -> dict:
        result: dict = {}
        result["cpu_usage"] = to_class(CPUUsage, self.cpu_usage)
        result["system_cpu_usage"] = from_int(self.system_cpu_usage)
        result["online_cpus"] = from_int(self.online_cpus)
        result["throttling_data"] = to_class(ThrottlingData, self.throttling_data)
        return result


class MemoryStats:
    usage: int
    stats: Dict[str, int]
    limit: int

    def __init__(self, usage: int, stats: Dict[str, int], limit: int) -> None:
        self.usage = usage
        self.stats = stats
        self.limit = limit

    @staticmethod
    def from_dict(obj: Any) -> 'MemoryStats':
        assert isinstance(obj, dict)
        usage = from_int(obj.get("usage"))
        stats = from_dict(from_int, obj.get("stats"))
        limit = from_int(obj.get("limit"))
        return MemoryStats(usage, stats, limit)

    def to_dict(self) -> dict:
        result: dict = {}
        result["usage"] = from_int(self.usage)
        result["stats"] = from_dict(from_int, self.stats)
        result["limit"] = from_int(self.limit)
        return result


class Eth0:
    rx_bytes: int
    rx_packets: int
    rx_errors: int
    rx_dropped: int
    tx_bytes: int
    tx_packets: int
    tx_errors: int
    tx_dropped: int

    def __init__(self, rx_bytes: int, rx_packets: int, rx_errors: int, rx_dropped: int, tx_bytes: int, tx_packets: int, tx_errors: int, tx_dropped: int) -> None:
        self.rx_bytes = rx_bytes
        self.rx_packets = rx_packets
        self.rx_errors = rx_errors
        self.rx_dropped = rx_dropped
        self.tx_bytes = tx_bytes
        self.tx_packets = tx_packets
        self.tx_errors = tx_errors
        self.tx_dropped = tx_dropped

    @staticmethod
    def from_dict(obj: Any) -> 'Eth0':
        assert isinstance(obj, dict)
        rx_bytes = from_int(obj.get("rx_bytes"))
        rx_packets = from_int(obj.get("rx_packets"))
        rx_errors = from_int(obj.get("rx_errors"))
        rx_dropped = from_int(obj.get("rx_dropped"))
        tx_bytes = from_int(obj.get("tx_bytes"))
        tx_packets = from_int(obj.get("tx_packets"))
        tx_errors = from_int(obj.get("tx_errors"))
        tx_dropped = from_int(obj.get("tx_dropped"))
        return Eth0(rx_bytes, rx_packets, rx_errors, rx_dropped, tx_bytes, tx_packets, tx_errors, tx_dropped)

    def to_dict(self) -> dict:
        result: dict = {}
        result["rx_bytes"] = from_int(self.rx_bytes)
        result["rx_packets"] = from_int(self.rx_packets)
        result["rx_errors"] = from_int(self.rx_errors)
        result["rx_dropped"] = from_int(self.rx_dropped)
        result["tx_bytes"] = from_int(self.tx_bytes)
        result["tx_packets"] = from_int(self.tx_packets)
        result["tx_errors"] = from_int(self.tx_errors)
        result["tx_dropped"] = from_int(self.tx_dropped)
        return result


class Networks:
    eth0: Eth0

    def __init__(self, eth0: Eth0) -> None:
        self.eth0 = eth0

    @staticmethod
    def from_dict(obj: Any) -> 'Networks':
        assert isinstance(obj, dict)
        eth0 = Eth0.from_dict(obj.get("eth0"))
        return Networks(eth0)

    def to_dict(self) -> dict:
        result: dict = {}
        result["eth0"] = to_class(Eth0, self.eth0)
        return result


class PidsStats:
    current: int
    limit: int

    def __init__(self, current: int, limit: int) -> None:
        self.current = current
        self.limit = limit

    @staticmethod
    def from_dict(obj: Any) -> 'PidsStats':
        assert isinstance(obj, dict)
        current = from_int(obj.get("current"))
        limit = from_int(obj.get("limit"))
        return PidsStats(current, limit)

    def to_dict(self) -> dict:
        result: dict = {}
        result["current"] = from_int(self.current)
        result["limit"] = from_int(self.limit)
        return result


class PrecpuStats:
    cpu_usage: CPUUsage
    throttling_data: ThrottlingData

    def __init__(self, cpu_usage: CPUUsage, throttling_data: ThrottlingData) -> None:
        self.cpu_usage = cpu_usage
        self.throttling_data = throttling_data

    @staticmethod
    def from_dict(obj: Any) -> 'PrecpuStats':
        assert isinstance(obj, dict)
        cpu_usage = CPUUsage.from_dict(obj.get("cpu_usage"))
        throttling_data = ThrottlingData.from_dict(obj.get("throttling_data"))
        return PrecpuStats(cpu_usage, throttling_data)

    def to_dict(self) -> dict:
        result: dict = {}
        result["cpu_usage"] = to_class(CPUUsage, self.cpu_usage)
        result["throttling_data"] = to_class(ThrottlingData, self.throttling_data)
        return result


class StorageStats:
    pass

    def __init__(self, ) -> None:
        pass

    @staticmethod
    def from_dict(obj: Any) -> 'StorageStats':
        assert isinstance(obj, dict)
        return StorageStats()

    def to_dict(self) -> dict:
        result: dict = {}
        return result


class Stats:
    read: datetime
    preread: datetime
    pids_stats: PidsStats
    blkio_stats: BlkioStats
    num_procs: int
    storage_stats: StorageStats
    cpu_stats: CPUStats
    precpu_stats: PrecpuStats
    memory_stats: MemoryStats
    name: str
    id: str
    networks: Networks

    def __init__(self, read: datetime, preread: datetime, pids_stats: PidsStats, blkio_stats: BlkioStats, num_procs: int, storage_stats: StorageStats, cpu_stats: CPUStats, precpu_stats: PrecpuStats, memory_stats: MemoryStats, name: str, id: str, networks: Networks) -> None:
        self.read = read
        self.preread = preread
        self.pids_stats = pids_stats
        self.blkio_stats = blkio_stats
        self.num_procs = num_procs
        self.storage_stats = storage_stats
        self.cpu_stats = cpu_stats
        self.precpu_stats = precpu_stats
        self.memory_stats = memory_stats
        self.name = name
        self.id = id
        self.networks = networks

    @staticmethod
    def from_dict(obj: Any) -> 'Stats':
        assert isinstance(obj, dict)
        read = from_datetime(obj.get("read"))
        preread = from_datetime(obj.get("preread"))
        pids_stats = PidsStats.from_dict(obj.get("pids_stats"))
        blkio_stats = BlkioStats.from_dict(obj.get("blkio_stats"))
        num_procs = from_int(obj.get("num_procs"))
        storage_stats = StorageStats.from_dict(obj.get("storage_stats"))
        cpu_stats = CPUStats.from_dict(obj.get("cpu_stats"))
        precpu_stats = PrecpuStats.from_dict(obj.get("precpu_stats"))
        memory_stats = MemoryStats.from_dict(obj.get("memory_stats"))
        name = from_str(obj.get("name"))
        id = from_str(obj.get("id"))
        networks = Networks.from_dict(obj.get("networks"))
        return Stats(read, preread, pids_stats, blkio_stats, num_procs, storage_stats, cpu_stats, precpu_stats, memory_stats, name, id, networks)

    def to_dict(self) -> dict:
        result: dict = {}
        result["read"] = self.read.isoformat()
        result["preread"] = self.preread.isoformat()
        result["pids_stats"] = to_class(PidsStats, self.pids_stats)
        result["blkio_stats"] = to_class(BlkioStats, self.blkio_stats)
        result["num_procs"] = from_int(self.num_procs)
        result["storage_stats"] = to_class(StorageStats, self.storage_stats)
        result["cpu_stats"] = to_class(CPUStats, self.cpu_stats)
        result["precpu_stats"] = to_class(PrecpuStats, self.precpu_stats)
        result["memory_stats"] = to_class(MemoryStats, self.memory_stats)
        result["name"] = from_str(self.name)
        result["id"] = from_str(self.id)
        result["networks"] = to_class(Networks, self.networks)
        return result


def stats_from_dict(s: Any) -> Stats:
    return Stats.from_dict(s)


def stats_to_dict(x: Stats) -> Any:
    return to_class(Stats, x)

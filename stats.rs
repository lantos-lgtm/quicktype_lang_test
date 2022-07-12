// Example code that deserializes and serializes the model.
// extern crate serde;
// #[macro_use]
// extern crate serde_derive;
// extern crate serde_json;
//
// use generated_module::[object Object];
//
// fn main() {
//     let json = r#"{"answer": 42}"#;
//     let model: [object Object] = serde_json::from_str(&json).unwrap();
// }

extern crate serde_derive;
use std::collections::HashMap;

#[derive(Serialize, Deserialize)]
pub struct Stats {
    #[serde(rename = "read")]
    read: String,

    #[serde(rename = "preread")]
    preread: String,

    #[serde(rename = "pids_stats")]
    pids_stats: PidsStats,

    #[serde(rename = "blkio_stats")]
    blkio_stats: BlkioStats,

    #[serde(rename = "num_procs")]
    num_procs: i64,

    #[serde(rename = "storage_stats")]
    storage_stats: StorageStats,

    #[serde(rename = "cpu_stats")]
    cpu_stats: CpuStats,

    #[serde(rename = "precpu_stats")]
    precpu_stats: PrecpuStats,

    #[serde(rename = "memory_stats")]
    memory_stats: MemoryStats,

    #[serde(rename = "name")]
    name: String,

    #[serde(rename = "id")]
    id: String,

    #[serde(rename = "networks")]
    networks: Networks,
}

#[derive(Serialize, Deserialize)]
pub struct BlkioStats {
    #[serde(rename = "io_service_bytes_recursive")]
    io_service_bytes_recursive: Vec<IoServiceBytesRecursive>,

    #[serde(rename = "io_serviced_recursive")]
    io_serviced_recursive: Option<serde_json::Value>,

    #[serde(rename = "io_queue_recursive")]
    io_queue_recursive: Option<serde_json::Value>,

    #[serde(rename = "io_service_time_recursive")]
    io_service_time_recursive: Option<serde_json::Value>,

    #[serde(rename = "io_wait_time_recursive")]
    io_wait_time_recursive: Option<serde_json::Value>,

    #[serde(rename = "io_merged_recursive")]
    io_merged_recursive: Option<serde_json::Value>,

    #[serde(rename = "io_time_recursive")]
    io_time_recursive: Option<serde_json::Value>,

    #[serde(rename = "sectors_recursive")]
    sectors_recursive: Option<serde_json::Value>,
}

#[derive(Serialize, Deserialize)]
pub struct IoServiceBytesRecursive {
    #[serde(rename = "major")]
    major: i64,

    #[serde(rename = "minor")]
    minor: i64,

    #[serde(rename = "op")]
    op: String,

    #[serde(rename = "value")]
    value: i64,
}

#[derive(Serialize, Deserialize)]
pub struct CpuStats {
    #[serde(rename = "cpu_usage")]
    cpu_usage: CpuUsage,

    #[serde(rename = "system_cpu_usage")]
    system_cpu_usage: i64,

    #[serde(rename = "online_cpus")]
    online_cpus: i64,

    #[serde(rename = "throttling_data")]
    throttling_data: ThrottlingData,
}

#[derive(Serialize, Deserialize)]
pub struct CpuUsage {
    #[serde(rename = "total_usage")]
    total_usage: i64,

    #[serde(rename = "usage_in_kernelmode")]
    usage_in_kernelmode: i64,

    #[serde(rename = "usage_in_usermode")]
    usage_in_usermode: i64,
}

#[derive(Serialize, Deserialize)]
pub struct ThrottlingData {
    #[serde(rename = "periods")]
    periods: i64,

    #[serde(rename = "throttled_periods")]
    throttled_periods: i64,

    #[serde(rename = "throttled_time")]
    throttled_time: i64,
}

#[derive(Serialize, Deserialize)]
pub struct MemoryStats {
    #[serde(rename = "usage")]
    usage: i64,

    #[serde(rename = "stats")]
    stats: HashMap<String, i64>,

    #[serde(rename = "limit")]
    limit: i64,
}

#[derive(Serialize, Deserialize)]
pub struct Networks {
    #[serde(rename = "eth0")]
    eth0: Eth0,
}

#[derive(Serialize, Deserialize)]
pub struct Eth0 {
    #[serde(rename = "rx_bytes")]
    rx_bytes: i64,

    #[serde(rename = "rx_packets")]
    rx_packets: i64,

    #[serde(rename = "rx_errors")]
    rx_errors: i64,

    #[serde(rename = "rx_dropped")]
    rx_dropped: i64,

    #[serde(rename = "tx_bytes")]
    tx_bytes: i64,

    #[serde(rename = "tx_packets")]
    tx_packets: i64,

    #[serde(rename = "tx_errors")]
    tx_errors: i64,

    #[serde(rename = "tx_dropped")]
    tx_dropped: i64,
}

#[derive(Serialize, Deserialize)]
pub struct PidsStats {
    #[serde(rename = "current")]
    current: i64,

    #[serde(rename = "limit")]
    limit: i64,
}

#[derive(Serialize, Deserialize)]
pub struct PrecpuStats {
    #[serde(rename = "cpu_usage")]
    cpu_usage: CpuUsage,

    #[serde(rename = "throttling_data")]
    throttling_data: ThrottlingData,
}

#[derive(Serialize, Deserialize)]
pub struct StorageStats {
}

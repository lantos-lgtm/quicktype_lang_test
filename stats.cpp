//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Stats data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>

namespace quicktype {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    class IoServiceBytesRecursive {
        public:
        IoServiceBytesRecursive() = default;
        virtual ~IoServiceBytesRecursive() = default;

        private:
        int64_t major;
        int64_t minor;
        std::string op;
        int64_t value;

        public:
        const int64_t & get_major() const { return major; }
        int64_t & get_mutable_major() { return major; }
        void set_major(const int64_t & value) { this->major = value; }

        const int64_t & get_minor() const { return minor; }
        int64_t & get_mutable_minor() { return minor; }
        void set_minor(const int64_t & value) { this->minor = value; }

        const std::string & get_op() const { return op; }
        std::string & get_mutable_op() { return op; }
        void set_op(const std::string & value) { this->op = value; }

        const int64_t & get_value() const { return value; }
        int64_t & get_mutable_value() { return value; }
        void set_value(const int64_t & value) { this->value = value; }
    };

    class BlkioStats {
        public:
        BlkioStats() = default;
        virtual ~BlkioStats() = default;

        private:
        std::vector<IoServiceBytesRecursive> io_service_bytes_recursive;
        nlohmann::json io_serviced_recursive;
        nlohmann::json io_queue_recursive;
        nlohmann::json io_service_time_recursive;
        nlohmann::json io_wait_time_recursive;
        nlohmann::json io_merged_recursive;
        nlohmann::json io_time_recursive;
        nlohmann::json sectors_recursive;

        public:
        const std::vector<IoServiceBytesRecursive> & get_io_service_bytes_recursive() const { return io_service_bytes_recursive; }
        std::vector<IoServiceBytesRecursive> & get_mutable_io_service_bytes_recursive() { return io_service_bytes_recursive; }
        void set_io_service_bytes_recursive(const std::vector<IoServiceBytesRecursive> & value) { this->io_service_bytes_recursive = value; }

        const nlohmann::json & get_io_serviced_recursive() const { return io_serviced_recursive; }
        nlohmann::json & get_mutable_io_serviced_recursive() { return io_serviced_recursive; }
        void set_io_serviced_recursive(const nlohmann::json & value) { this->io_serviced_recursive = value; }

        const nlohmann::json & get_io_queue_recursive() const { return io_queue_recursive; }
        nlohmann::json & get_mutable_io_queue_recursive() { return io_queue_recursive; }
        void set_io_queue_recursive(const nlohmann::json & value) { this->io_queue_recursive = value; }

        const nlohmann::json & get_io_service_time_recursive() const { return io_service_time_recursive; }
        nlohmann::json & get_mutable_io_service_time_recursive() { return io_service_time_recursive; }
        void set_io_service_time_recursive(const nlohmann::json & value) { this->io_service_time_recursive = value; }

        const nlohmann::json & get_io_wait_time_recursive() const { return io_wait_time_recursive; }
        nlohmann::json & get_mutable_io_wait_time_recursive() { return io_wait_time_recursive; }
        void set_io_wait_time_recursive(const nlohmann::json & value) { this->io_wait_time_recursive = value; }

        const nlohmann::json & get_io_merged_recursive() const { return io_merged_recursive; }
        nlohmann::json & get_mutable_io_merged_recursive() { return io_merged_recursive; }
        void set_io_merged_recursive(const nlohmann::json & value) { this->io_merged_recursive = value; }

        const nlohmann::json & get_io_time_recursive() const { return io_time_recursive; }
        nlohmann::json & get_mutable_io_time_recursive() { return io_time_recursive; }
        void set_io_time_recursive(const nlohmann::json & value) { this->io_time_recursive = value; }

        const nlohmann::json & get_sectors_recursive() const { return sectors_recursive; }
        nlohmann::json & get_mutable_sectors_recursive() { return sectors_recursive; }
        void set_sectors_recursive(const nlohmann::json & value) { this->sectors_recursive = value; }
    };

    class CpuUsage {
        public:
        CpuUsage() = default;
        virtual ~CpuUsage() = default;

        private:
        int64_t total_usage;
        int64_t usage_in_kernelmode;
        int64_t usage_in_usermode;

        public:
        const int64_t & get_total_usage() const { return total_usage; }
        int64_t & get_mutable_total_usage() { return total_usage; }
        void set_total_usage(const int64_t & value) { this->total_usage = value; }

        const int64_t & get_usage_in_kernelmode() const { return usage_in_kernelmode; }
        int64_t & get_mutable_usage_in_kernelmode() { return usage_in_kernelmode; }
        void set_usage_in_kernelmode(const int64_t & value) { this->usage_in_kernelmode = value; }

        const int64_t & get_usage_in_usermode() const { return usage_in_usermode; }
        int64_t & get_mutable_usage_in_usermode() { return usage_in_usermode; }
        void set_usage_in_usermode(const int64_t & value) { this->usage_in_usermode = value; }
    };

    class ThrottlingData {
        public:
        ThrottlingData() = default;
        virtual ~ThrottlingData() = default;

        private:
        int64_t periods;
        int64_t throttled_periods;
        int64_t throttled_time;

        public:
        const int64_t & get_periods() const { return periods; }
        int64_t & get_mutable_periods() { return periods; }
        void set_periods(const int64_t & value) { this->periods = value; }

        const int64_t & get_throttled_periods() const { return throttled_periods; }
        int64_t & get_mutable_throttled_periods() { return throttled_periods; }
        void set_throttled_periods(const int64_t & value) { this->throttled_periods = value; }

        const int64_t & get_throttled_time() const { return throttled_time; }
        int64_t & get_mutable_throttled_time() { return throttled_time; }
        void set_throttled_time(const int64_t & value) { this->throttled_time = value; }
    };

    class CpuStats {
        public:
        CpuStats() = default;
        virtual ~CpuStats() = default;

        private:
        CpuUsage cpu_usage;
        int64_t system_cpu_usage;
        int64_t online_cpus;
        ThrottlingData throttling_data;

        public:
        const CpuUsage & get_cpu_usage() const { return cpu_usage; }
        CpuUsage & get_mutable_cpu_usage() { return cpu_usage; }
        void set_cpu_usage(const CpuUsage & value) { this->cpu_usage = value; }

        const int64_t & get_system_cpu_usage() const { return system_cpu_usage; }
        int64_t & get_mutable_system_cpu_usage() { return system_cpu_usage; }
        void set_system_cpu_usage(const int64_t & value) { this->system_cpu_usage = value; }

        const int64_t & get_online_cpus() const { return online_cpus; }
        int64_t & get_mutable_online_cpus() { return online_cpus; }
        void set_online_cpus(const int64_t & value) { this->online_cpus = value; }

        const ThrottlingData & get_throttling_data() const { return throttling_data; }
        ThrottlingData & get_mutable_throttling_data() { return throttling_data; }
        void set_throttling_data(const ThrottlingData & value) { this->throttling_data = value; }
    };

    class MemoryStats {
        public:
        MemoryStats() = default;
        virtual ~MemoryStats() = default;

        private:
        int64_t usage;
        std::map<std::string, int64_t> stats;
        int64_t limit;

        public:
        const int64_t & get_usage() const { return usage; }
        int64_t & get_mutable_usage() { return usage; }
        void set_usage(const int64_t & value) { this->usage = value; }

        const std::map<std::string, int64_t> & get_stats() const { return stats; }
        std::map<std::string, int64_t> & get_mutable_stats() { return stats; }
        void set_stats(const std::map<std::string, int64_t> & value) { this->stats = value; }

        const int64_t & get_limit() const { return limit; }
        int64_t & get_mutable_limit() { return limit; }
        void set_limit(const int64_t & value) { this->limit = value; }
    };

    class Eth0 {
        public:
        Eth0() = default;
        virtual ~Eth0() = default;

        private:
        int64_t rx_bytes;
        int64_t rx_packets;
        int64_t rx_errors;
        int64_t rx_dropped;
        int64_t tx_bytes;
        int64_t tx_packets;
        int64_t tx_errors;
        int64_t tx_dropped;

        public:
        const int64_t & get_rx_bytes() const { return rx_bytes; }
        int64_t & get_mutable_rx_bytes() { return rx_bytes; }
        void set_rx_bytes(const int64_t & value) { this->rx_bytes = value; }

        const int64_t & get_rx_packets() const { return rx_packets; }
        int64_t & get_mutable_rx_packets() { return rx_packets; }
        void set_rx_packets(const int64_t & value) { this->rx_packets = value; }

        const int64_t & get_rx_errors() const { return rx_errors; }
        int64_t & get_mutable_rx_errors() { return rx_errors; }
        void set_rx_errors(const int64_t & value) { this->rx_errors = value; }

        const int64_t & get_rx_dropped() const { return rx_dropped; }
        int64_t & get_mutable_rx_dropped() { return rx_dropped; }
        void set_rx_dropped(const int64_t & value) { this->rx_dropped = value; }

        const int64_t & get_tx_bytes() const { return tx_bytes; }
        int64_t & get_mutable_tx_bytes() { return tx_bytes; }
        void set_tx_bytes(const int64_t & value) { this->tx_bytes = value; }

        const int64_t & get_tx_packets() const { return tx_packets; }
        int64_t & get_mutable_tx_packets() { return tx_packets; }
        void set_tx_packets(const int64_t & value) { this->tx_packets = value; }

        const int64_t & get_tx_errors() const { return tx_errors; }
        int64_t & get_mutable_tx_errors() { return tx_errors; }
        void set_tx_errors(const int64_t & value) { this->tx_errors = value; }

        const int64_t & get_tx_dropped() const { return tx_dropped; }
        int64_t & get_mutable_tx_dropped() { return tx_dropped; }
        void set_tx_dropped(const int64_t & value) { this->tx_dropped = value; }
    };

    class Networks {
        public:
        Networks() = default;
        virtual ~Networks() = default;

        private:
        Eth0 eth0;

        public:
        const Eth0 & get_eth0() const { return eth0; }
        Eth0 & get_mutable_eth0() { return eth0; }
        void set_eth0(const Eth0 & value) { this->eth0 = value; }
    };

    class PidsStats {
        public:
        PidsStats() = default;
        virtual ~PidsStats() = default;

        private:
        int64_t current;
        int64_t limit;

        public:
        const int64_t & get_current() const { return current; }
        int64_t & get_mutable_current() { return current; }
        void set_current(const int64_t & value) { this->current = value; }

        const int64_t & get_limit() const { return limit; }
        int64_t & get_mutable_limit() { return limit; }
        void set_limit(const int64_t & value) { this->limit = value; }
    };

    class PrecpuStats {
        public:
        PrecpuStats() = default;
        virtual ~PrecpuStats() = default;

        private:
        CpuUsage cpu_usage;
        ThrottlingData throttling_data;

        public:
        const CpuUsage & get_cpu_usage() const { return cpu_usage; }
        CpuUsage & get_mutable_cpu_usage() { return cpu_usage; }
        void set_cpu_usage(const CpuUsage & value) { this->cpu_usage = value; }

        const ThrottlingData & get_throttling_data() const { return throttling_data; }
        ThrottlingData & get_mutable_throttling_data() { return throttling_data; }
        void set_throttling_data(const ThrottlingData & value) { this->throttling_data = value; }
    };

    class StorageStats {
        public:
        StorageStats() = default;
        virtual ~StorageStats() = default;

        private:

        public:
    };

    class Stats {
        public:
        Stats() = default;
        virtual ~Stats() = default;

        private:
        std::string read;
        std::string preread;
        PidsStats pids_stats;
        BlkioStats blkio_stats;
        int64_t num_procs;
        StorageStats storage_stats;
        CpuStats cpu_stats;
        PrecpuStats precpu_stats;
        MemoryStats memory_stats;
        std::string name;
        std::string id;
        Networks networks;

        public:
        const std::string & get_read() const { return read; }
        std::string & get_mutable_read() { return read; }
        void set_read(const std::string & value) { this->read = value; }

        const std::string & get_preread() const { return preread; }
        std::string & get_mutable_preread() { return preread; }
        void set_preread(const std::string & value) { this->preread = value; }

        const PidsStats & get_pids_stats() const { return pids_stats; }
        PidsStats & get_mutable_pids_stats() { return pids_stats; }
        void set_pids_stats(const PidsStats & value) { this->pids_stats = value; }

        const BlkioStats & get_blkio_stats() const { return blkio_stats; }
        BlkioStats & get_mutable_blkio_stats() { return blkio_stats; }
        void set_blkio_stats(const BlkioStats & value) { this->blkio_stats = value; }

        const int64_t & get_num_procs() const { return num_procs; }
        int64_t & get_mutable_num_procs() { return num_procs; }
        void set_num_procs(const int64_t & value) { this->num_procs = value; }

        const StorageStats & get_storage_stats() const { return storage_stats; }
        StorageStats & get_mutable_storage_stats() { return storage_stats; }
        void set_storage_stats(const StorageStats & value) { this->storage_stats = value; }

        const CpuStats & get_cpu_stats() const { return cpu_stats; }
        CpuStats & get_mutable_cpu_stats() { return cpu_stats; }
        void set_cpu_stats(const CpuStats & value) { this->cpu_stats = value; }

        const PrecpuStats & get_precpu_stats() const { return precpu_stats; }
        PrecpuStats & get_mutable_precpu_stats() { return precpu_stats; }
        void set_precpu_stats(const PrecpuStats & value) { this->precpu_stats = value; }

        const MemoryStats & get_memory_stats() const { return memory_stats; }
        MemoryStats & get_mutable_memory_stats() { return memory_stats; }
        void set_memory_stats(const MemoryStats & value) { this->memory_stats = value; }

        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const std::string & get_id() const { return id; }
        std::string & get_mutable_id() { return id; }
        void set_id(const std::string & value) { this->id = value; }

        const Networks & get_networks() const { return networks; }
        Networks & get_mutable_networks() { return networks; }
        void set_networks(const Networks & value) { this->networks = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, quicktype::IoServiceBytesRecursive & x);
    void to_json(json & j, const quicktype::IoServiceBytesRecursive & x);

    void from_json(const json & j, quicktype::BlkioStats & x);
    void to_json(json & j, const quicktype::BlkioStats & x);

    void from_json(const json & j, quicktype::CpuUsage & x);
    void to_json(json & j, const quicktype::CpuUsage & x);

    void from_json(const json & j, quicktype::ThrottlingData & x);
    void to_json(json & j, const quicktype::ThrottlingData & x);

    void from_json(const json & j, quicktype::CpuStats & x);
    void to_json(json & j, const quicktype::CpuStats & x);

    void from_json(const json & j, quicktype::MemoryStats & x);
    void to_json(json & j, const quicktype::MemoryStats & x);

    void from_json(const json & j, quicktype::Eth0 & x);
    void to_json(json & j, const quicktype::Eth0 & x);

    void from_json(const json & j, quicktype::Networks & x);
    void to_json(json & j, const quicktype::Networks & x);

    void from_json(const json & j, quicktype::PidsStats & x);
    void to_json(json & j, const quicktype::PidsStats & x);

    void from_json(const json & j, quicktype::PrecpuStats & x);
    void to_json(json & j, const quicktype::PrecpuStats & x);

    void from_json(const json & j, quicktype::StorageStats & x);
    void to_json(json & j, const quicktype::StorageStats & x);

    void from_json(const json & j, quicktype::Stats & x);
    void to_json(json & j, const quicktype::Stats & x);

    inline void from_json(const json & j, quicktype::IoServiceBytesRecursive& x) {
        x.set_major(j.at("major").get<int64_t>());
        x.set_minor(j.at("minor").get<int64_t>());
        x.set_op(j.at("op").get<std::string>());
        x.set_value(j.at("value").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::IoServiceBytesRecursive & x) {
        j = json::object();
        j["major"] = x.get_major();
        j["minor"] = x.get_minor();
        j["op"] = x.get_op();
        j["value"] = x.get_value();
    }

    inline void from_json(const json & j, quicktype::BlkioStats& x) {
        x.set_io_service_bytes_recursive(j.at("io_service_bytes_recursive").get<std::vector<quicktype::IoServiceBytesRecursive>>());
        x.set_io_serviced_recursive(quicktype::get_untyped(j, "io_serviced_recursive"));
        x.set_io_queue_recursive(quicktype::get_untyped(j, "io_queue_recursive"));
        x.set_io_service_time_recursive(quicktype::get_untyped(j, "io_service_time_recursive"));
        x.set_io_wait_time_recursive(quicktype::get_untyped(j, "io_wait_time_recursive"));
        x.set_io_merged_recursive(quicktype::get_untyped(j, "io_merged_recursive"));
        x.set_io_time_recursive(quicktype::get_untyped(j, "io_time_recursive"));
        x.set_sectors_recursive(quicktype::get_untyped(j, "sectors_recursive"));
    }

    inline void to_json(json & j, const quicktype::BlkioStats & x) {
        j = json::object();
        j["io_service_bytes_recursive"] = x.get_io_service_bytes_recursive();
        j["io_serviced_recursive"] = x.get_io_serviced_recursive();
        j["io_queue_recursive"] = x.get_io_queue_recursive();
        j["io_service_time_recursive"] = x.get_io_service_time_recursive();
        j["io_wait_time_recursive"] = x.get_io_wait_time_recursive();
        j["io_merged_recursive"] = x.get_io_merged_recursive();
        j["io_time_recursive"] = x.get_io_time_recursive();
        j["sectors_recursive"] = x.get_sectors_recursive();
    }

    inline void from_json(const json & j, quicktype::CpuUsage& x) {
        x.set_total_usage(j.at("total_usage").get<int64_t>());
        x.set_usage_in_kernelmode(j.at("usage_in_kernelmode").get<int64_t>());
        x.set_usage_in_usermode(j.at("usage_in_usermode").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::CpuUsage & x) {
        j = json::object();
        j["total_usage"] = x.get_total_usage();
        j["usage_in_kernelmode"] = x.get_usage_in_kernelmode();
        j["usage_in_usermode"] = x.get_usage_in_usermode();
    }

    inline void from_json(const json & j, quicktype::ThrottlingData& x) {
        x.set_periods(j.at("periods").get<int64_t>());
        x.set_throttled_periods(j.at("throttled_periods").get<int64_t>());
        x.set_throttled_time(j.at("throttled_time").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::ThrottlingData & x) {
        j = json::object();
        j["periods"] = x.get_periods();
        j["throttled_periods"] = x.get_throttled_periods();
        j["throttled_time"] = x.get_throttled_time();
    }

    inline void from_json(const json & j, quicktype::CpuStats& x) {
        x.set_cpu_usage(j.at("cpu_usage").get<quicktype::CpuUsage>());
        x.set_system_cpu_usage(j.at("system_cpu_usage").get<int64_t>());
        x.set_online_cpus(j.at("online_cpus").get<int64_t>());
        x.set_throttling_data(j.at("throttling_data").get<quicktype::ThrottlingData>());
    }

    inline void to_json(json & j, const quicktype::CpuStats & x) {
        j = json::object();
        j["cpu_usage"] = x.get_cpu_usage();
        j["system_cpu_usage"] = x.get_system_cpu_usage();
        j["online_cpus"] = x.get_online_cpus();
        j["throttling_data"] = x.get_throttling_data();
    }

    inline void from_json(const json & j, quicktype::MemoryStats& x) {
        x.set_usage(j.at("usage").get<int64_t>());
        x.set_stats(j.at("stats").get<std::map<std::string, int64_t>>());
        x.set_limit(j.at("limit").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::MemoryStats & x) {
        j = json::object();
        j["usage"] = x.get_usage();
        j["stats"] = x.get_stats();
        j["limit"] = x.get_limit();
    }

    inline void from_json(const json & j, quicktype::Eth0& x) {
        x.set_rx_bytes(j.at("rx_bytes").get<int64_t>());
        x.set_rx_packets(j.at("rx_packets").get<int64_t>());
        x.set_rx_errors(j.at("rx_errors").get<int64_t>());
        x.set_rx_dropped(j.at("rx_dropped").get<int64_t>());
        x.set_tx_bytes(j.at("tx_bytes").get<int64_t>());
        x.set_tx_packets(j.at("tx_packets").get<int64_t>());
        x.set_tx_errors(j.at("tx_errors").get<int64_t>());
        x.set_tx_dropped(j.at("tx_dropped").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::Eth0 & x) {
        j = json::object();
        j["rx_bytes"] = x.get_rx_bytes();
        j["rx_packets"] = x.get_rx_packets();
        j["rx_errors"] = x.get_rx_errors();
        j["rx_dropped"] = x.get_rx_dropped();
        j["tx_bytes"] = x.get_tx_bytes();
        j["tx_packets"] = x.get_tx_packets();
        j["tx_errors"] = x.get_tx_errors();
        j["tx_dropped"] = x.get_tx_dropped();
    }

    inline void from_json(const json & j, quicktype::Networks& x) {
        x.set_eth0(j.at("eth0").get<quicktype::Eth0>());
    }

    inline void to_json(json & j, const quicktype::Networks & x) {
        j = json::object();
        j["eth0"] = x.get_eth0();
    }

    inline void from_json(const json & j, quicktype::PidsStats& x) {
        x.set_current(j.at("current").get<int64_t>());
        x.set_limit(j.at("limit").get<int64_t>());
    }

    inline void to_json(json & j, const quicktype::PidsStats & x) {
        j = json::object();
        j["current"] = x.get_current();
        j["limit"] = x.get_limit();
    }

    inline void from_json(const json & j, quicktype::PrecpuStats& x) {
        x.set_cpu_usage(j.at("cpu_usage").get<quicktype::CpuUsage>());
        x.set_throttling_data(j.at("throttling_data").get<quicktype::ThrottlingData>());
    }

    inline void to_json(json & j, const quicktype::PrecpuStats & x) {
        j = json::object();
        j["cpu_usage"] = x.get_cpu_usage();
        j["throttling_data"] = x.get_throttling_data();
    }

    inline void from_json(const json & j, quicktype::StorageStats& x) {
    }

    inline void to_json(json & j, const quicktype::StorageStats & x) {
        j = json::object();
    }

    inline void from_json(const json & j, quicktype::Stats& x) {
        x.set_read(j.at("read").get<std::string>());
        x.set_preread(j.at("preread").get<std::string>());
        x.set_pids_stats(j.at("pids_stats").get<quicktype::PidsStats>());
        x.set_blkio_stats(j.at("blkio_stats").get<quicktype::BlkioStats>());
        x.set_num_procs(j.at("num_procs").get<int64_t>());
        x.set_storage_stats(j.at("storage_stats").get<quicktype::StorageStats>());
        x.set_cpu_stats(j.at("cpu_stats").get<quicktype::CpuStats>());
        x.set_precpu_stats(j.at("precpu_stats").get<quicktype::PrecpuStats>());
        x.set_memory_stats(j.at("memory_stats").get<quicktype::MemoryStats>());
        x.set_name(j.at("name").get<std::string>());
        x.set_id(j.at("id").get<std::string>());
        x.set_networks(j.at("networks").get<quicktype::Networks>());
    }

    inline void to_json(json & j, const quicktype::Stats & x) {
        j = json::object();
        j["read"] = x.get_read();
        j["preread"] = x.get_preread();
        j["pids_stats"] = x.get_pids_stats();
        j["blkio_stats"] = x.get_blkio_stats();
        j["num_procs"] = x.get_num_procs();
        j["storage_stats"] = x.get_storage_stats();
        j["cpu_stats"] = x.get_cpu_stats();
        j["precpu_stats"] = x.get_precpu_stats();
        j["memory_stats"] = x.get_memory_stats();
        j["name"] = x.get_name();
        j["id"] = x.get_id();
        j["networks"] = x.get_networks();
    }
}

import jsony, tables, times, options

# nim manually created, jsony can auto coerces snake_case to camelCase
proc parseHook*(s: string, i: var int, v: var DateTime) =
    var str: string
    parseHook(s, i, str)
    v = str.parse("yyyy-MM-dd'T'HH':'mm':'ss'.'fffffffff'Z'")

type
    Stats* = object
        Read: DateTime
        Preread: DateTime
        PidsStats: PidsStats
        BlkioStats: BlkioStats
        NumProcs: uint32
        StorageStats: StorageStats
        CPUStats: CPUStats
        PrecpuStats: CPUStats
        MemoryStats: MemoryStats
        Name: string
        ID: string
        Networks: Table[string, NetworkStats] 

    BlkioStats = object
        IoServiceBytesRecursive: Option[seq[BlkioStatEntry]]
        IoServicedRecursive: Option[seq[BlkioStatEntry]]
        IoQueueRecursive: Option[seq[BlkioStatEntry]]
        IoServiceTimeRecursive: Option[seq[BlkioStatEntry]]
        IoWaitTimeRecursive: Option[seq[BlkioStatEntry]]
        IoMergedRecursive: Option[seq[BlkioStatEntry]]
        IoTimeRecursive: Option[seq[BlkioStatEntry]]
        SectorsRecursive: Option[seq[BlkioStatEntry]]

    BlkioStatEntry = object
        Major: uint64
        Minor: uint64
        Op: string
        Value: uint64

    CPUStats = object
        CPUUsage: CPUUsage
        SystemCPUUsage: uint64
        OnlineCpus: uint32
        ThrottlingData: ThrottlingData

    CPUUsage = object
        TotalUsage: uint64
        PercpuUsage: seq[uint64]
        UsageInKernelmode: uint64
        UsageInUsermode: uint64

    ThrottlingData = object
        Periods: uint64
        ThrottledPeriods: uint64
        ThrottledTime: uint64

    MemoryStats = object
        Usage: uint64
        Stats: Table[string, uint64]
        Limit: uint64

    NetworkStats = object
        RxBytes: uint64
        RxPackets: uint64
        RxErrors: uint64
        RxDropped: uint64
        TxBytes: uint64
        TxPackets: uint64
        TxErrors: uint64
        TxDropped: uint64

    PidsStats = object
        Current: uint64
        Limit: uint64

    StorageStats = object

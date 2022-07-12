// This file was generated from JSON Schema using quicktype, do not modify it directly.
// To parse and unparse this JSON data, add this code to your project and do:
//
//    stats, err := UnmarshalStats(bytes)
//    bytes, err = stats.Marshal()

package main

import "encoding/json"

func UnmarshalStats(data []byte) (Stats, error) {
	var r Stats
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Stats) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

type Stats struct {
	Read         string       `json:"read"`         
	Preread      string       `json:"preread"`      
	PidsStats    PidsStats    `json:"pids_stats"`   
	BlkioStats   BlkioStats   `json:"blkio_stats"`  
	NumProcs     int64        `json:"num_procs"`    
	StorageStats StorageStats `json:"storage_stats"`
	CPUStats     CPUStats     `json:"cpu_stats"`    
	PrecpuStats  PrecpuStats  `json:"precpu_stats"` 
	MemoryStats  MemoryStats  `json:"memory_stats"` 
	Name         string       `json:"name"`         
	ID           string       `json:"id"`           
	Networks     Networks     `json:"networks"`     
}

type BlkioStats struct {
	IoServiceBytesRecursive []IoServiceBytesRecursive `json:"io_service_bytes_recursive"`
	IoServicedRecursive     interface{}               `json:"io_serviced_recursive"`     
	IoQueueRecursive        interface{}               `json:"io_queue_recursive"`        
	IoServiceTimeRecursive  interface{}               `json:"io_service_time_recursive"` 
	IoWaitTimeRecursive     interface{}               `json:"io_wait_time_recursive"`    
	IoMergedRecursive       interface{}               `json:"io_merged_recursive"`       
	IoTimeRecursive         interface{}               `json:"io_time_recursive"`         
	SectorsRecursive        interface{}               `json:"sectors_recursive"`         
}

type IoServiceBytesRecursive struct {
	Major int64  `json:"major"`
	Minor int64  `json:"minor"`
	Op    string `json:"op"`   
	Value int64  `json:"value"`
}

type CPUStats struct {
	CPUUsage       CPUUsage       `json:"cpu_usage"`       
	SystemCPUUsage int64          `json:"system_cpu_usage"`
	OnlineCpus     int64          `json:"online_cpus"`     
	ThrottlingData ThrottlingData `json:"throttling_data"` 
}

type CPUUsage struct {
	TotalUsage        int64 `json:"total_usage"`        
	UsageInKernelmode int64 `json:"usage_in_kernelmode"`
	UsageInUsermode   int64 `json:"usage_in_usermode"`  
}

type ThrottlingData struct {
	Periods          int64 `json:"periods"`          
	ThrottledPeriods int64 `json:"throttled_periods"`
	ThrottledTime    int64 `json:"throttled_time"`   
}

type MemoryStats struct {
	Usage int64            `json:"usage"`
	Stats map[string]int64 `json:"stats"`
	Limit int64            `json:"limit"`
}

type Networks struct {
	Eth0 Eth0 `json:"eth0"`
}

type Eth0 struct {
	RxBytes   int64 `json:"rx_bytes"`  
	RxPackets int64 `json:"rx_packets"`
	RxErrors  int64 `json:"rx_errors"` 
	RxDropped int64 `json:"rx_dropped"`
	TxBytes   int64 `json:"tx_bytes"`  
	TxPackets int64 `json:"tx_packets"`
	TxErrors  int64 `json:"tx_errors"` 
	TxDropped int64 `json:"tx_dropped"`
}

type PidsStats struct {
	Current int64 `json:"current"`
	Limit   int64 `json:"limit"`  
}

type PrecpuStats struct {
	CPUUsage       CPUUsage       `json:"cpu_usage"`      
	ThrottlingData ThrottlingData `json:"throttling_data"`
}

type StorageStats struct {
}

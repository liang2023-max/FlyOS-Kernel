#pragma once

#include <string>
#include <vector>

// 获取CPU使用率的声明
int get_cpu_usage();

// 获取内存使用情况的声明
int get_memory_usage();

// 获取显卡使用情况的声明
int get_gpu_usage();

// 获取网络使用情况的声明
std::string get_network_usage();

// 获取当前运行的应用程序的声明
std::vector<std::string> get_running_applications();

// 监控系统的声明
void monitor_system(int interval = 1);

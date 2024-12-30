#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// 假设这些是您自制系统的API或方法，用于获取相关数据
int get_cpu_usage() {
    // TODO: 使用自制系统的方法获取CPU使用率
    return 50;  // 示例：返回50%
}

int get_memory_usage() {
    // TODO: 使用自制系统的方法获取内存使用情况
    return 70;  // 示例：返回70%
}

int get_gpu_usage() {
    // TODO: 使用自制系统的方法获取显卡使用情况
    return 30;  // 示例：返回30%
}

std::string get_network_usage() {
    // TODO: 使用自制系统的方法获取网卡流量
    return "下载: 100MB, 上传: 50MB";  // 示例返回
}

std::vector<std::string> get_running_applications() {
    // TODO: 使用自制系统的方法获取当前运行的应用程序
    return { "应用程序1", "应用程序2", "应用程序3" };  // 示例返回
}

void print_system_usage() {
    std::cout << "CPU使用率: " << get_cpu_usage() << "%" << std::endl;
    std::cout << "内存使用率: " << get_memory_usage() << "%" << std::endl;
    std::cout << "显卡使用率: " << get_gpu_usage() << "%" << std::endl;
    std::cout << "网络使用情况: " << get_network_usage() << std::endl;

    std::cout << "当前运行的应用程序:" << std::endl;
    for (const auto& app : get_running_applications()) {
        std::cout << "- " << app << std::endl;
    }
    std::cout << std::string(50, '-') << std::endl;
}

void monitor_system(int interval = 1) {
    while (true) {
        print_system_usage();
        std::this_thread::sleep_for(std::chrono::seconds(interval));
    }
}

int main() {
    monitor_system();
    return 0;
}

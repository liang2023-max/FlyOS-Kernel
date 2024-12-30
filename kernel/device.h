#include "device.h"
#include <iostream>

Device::Device() : running(false) {  // 使用成员初始化列表初始化 running
    // 构造函数的初始化逻辑（如果有）可以放在这里
}

Device::~Device() {
    // 析构函数清理资源的逻辑（如果有）可以放在这里
    stop(); // 确保设备在释放前停止运行
}

void Device::initialize() {
    // 设备的初始化逻辑
    std::cout << "Initializing device..." << std::endl;
    // 初始化代码...
}

void Device::start() {
    // 启动设备
    if (!running) {
        std::cout << "Starting device..." << std::endl;
        running = true;
        // 启动代码...
    }
    else {
        std::cout << "Device is already running." << std::endl;
    }
}

void Device::stop() {
    // 停止设备
    if (running) {
        std::cout << "Stopping device..." << std::endl;
        running = false;
        // 停止代码...
    }
    else {
        std::cout << "Device is not running." << std::endl;
    }
}

bool Device::isRunning() const noexcept {
    return running;
}

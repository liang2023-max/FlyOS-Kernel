#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

void getCpuInfo() {
    std::ifstream cpuFile("/proc/cpuinfo");
    std::string line;

    std::cout << "CPU ��Ϣ:\n";
    while (std::getline(cpuFile, line)) {
        if (line.find("model name") != std::string::npos ||
            line.find("processor") != std::string::npos) {
            std::cout << line << std::endl;
        }
    }
}

void getMemoryInfo() {
    std::ifstream memFile("/proc/meminfo");
    std::string line;

    std::cout << "�ڴ���Ϣ:\n";
    while (std::getline(memFile, line)) {
        if (line.find("MemTotal") != std::string::npos ||
            line.find("MemAvailable") != std::string::npos) {
            std::cout << line << std::endl;
        }
    }
}

void getDiskInfo() {
    std::ifstream diskFile("/proc/diskstats");
    std::string line;

    std::cout << "������Ϣ:\n";
    while (std::getline(diskFile, line)) {
        // ֻ�����һ�����̵���Ϣ
        if (line.find("sda") != std::string::npos) {
            std::cout << line << std::endl;
            break;
        }
    }
}

int main() {
    std::cout << "ϵͳ������Ϣ:\n";
    getCpuInfo();
    getMemoryInfo();
    getDiskInfo();

    return 0;
}

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// ������Щ��������ϵͳ��API�򷽷������ڻ�ȡ�������
int get_cpu_usage() {
    // TODO: ʹ������ϵͳ�ķ�����ȡCPUʹ����
    return 50;  // ʾ��������50%
}

int get_memory_usage() {
    // TODO: ʹ������ϵͳ�ķ�����ȡ�ڴ�ʹ�����
    return 70;  // ʾ��������70%
}

int get_gpu_usage() {
    // TODO: ʹ������ϵͳ�ķ�����ȡ�Կ�ʹ�����
    return 30;  // ʾ��������30%
}

std::string get_network_usage() {
    // TODO: ʹ������ϵͳ�ķ�����ȡ��������
    return "����: 100MB, �ϴ�: 50MB";  // ʾ������
}

std::vector<std::string> get_running_applications() {
    // TODO: ʹ������ϵͳ�ķ�����ȡ��ǰ���е�Ӧ�ó���
    return { "Ӧ�ó���1", "Ӧ�ó���2", "Ӧ�ó���3" };  // ʾ������
}

void print_system_usage() {
    std::cout << "CPUʹ����: " << get_cpu_usage() << "%" << std::endl;
    std::cout << "�ڴ�ʹ����: " << get_memory_usage() << "%" << std::endl;
    std::cout << "�Կ�ʹ����: " << get_gpu_usage() << "%" << std::endl;
    std::cout << "����ʹ�����: " << get_network_usage() << std::endl;

    std::cout << "��ǰ���е�Ӧ�ó���:" << std::endl;
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

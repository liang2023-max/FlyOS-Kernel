#pragma once

#include <string>
#include <vector>

// ��ȡCPUʹ���ʵ�����
int get_cpu_usage();

// ��ȡ�ڴ�ʹ�����������
int get_memory_usage();

// ��ȡ�Կ�ʹ�����������
int get_gpu_usage();

// ��ȡ����ʹ�����������
std::string get_network_usage();

// ��ȡ��ǰ���е�Ӧ�ó��������
std::vector<std::string> get_running_applications();

// ���ϵͳ������
void monitor_system(int interval = 1);

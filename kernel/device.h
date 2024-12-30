#include "device.h"
#include <iostream>

Device::Device() : running(false) {  // ʹ�ó�Ա��ʼ���б��ʼ�� running
    // ���캯���ĳ�ʼ���߼�������У����Է�������
}

Device::~Device() {
    // ��������������Դ���߼�������У����Է�������
    stop(); // ȷ���豸���ͷ�ǰֹͣ����
}

void Device::initialize() {
    // �豸�ĳ�ʼ���߼�
    std::cout << "Initializing device..." << std::endl;
    // ��ʼ������...
}

void Device::start() {
    // �����豸
    if (!running) {
        std::cout << "Starting device..." << std::endl;
        running = true;
        // ��������...
    }
    else {
        std::cout << "Device is already running." << std::endl;
    }
}

void Device::stop() {
    // ֹͣ�豸
    if (running) {
        std::cout << "Stopping device..." << std::endl;
        running = false;
        // ֹͣ����...
    }
    else {
        std::cout << "Device is not running." << std::endl;
    }
}

bool Device::isRunning() const noexcept {
    return running;
}

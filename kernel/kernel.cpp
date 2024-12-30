#include "kernel.h" // �����ں�ͷ�ļ�

// ���״̬�ֽ�
volatile uint8_t mouse_buttons = 0;
volatile int8_t mouse_x = 0, mouse_y = 0;

// ����˿ڶ�ȡ����
inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// ����˿�д�뺯��
inline void outb(uint16_t port, uint8_t value) {
    asm volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}

// ����жϴ�����
void mouse_handler() {
    if (inb(0x60) & 0x08) { // ��������ݿ���
        mouse_buttons = inb(0x60) & 0x07;
        mouse_x = inb(0x60);
        mouse_y = inb(0x60);
    }
}

// ��ʼ�����
void init_mouse() {
    set_idt_entry(IRQ12, mouse_handler);
    outb(0x64, 0xA8);
    outb(0x64, 0x20);
    uint8_t status = inb(0x60);
    outb(0x64, 0x60);
    outb(0x60, status | 2); // ��������ж�
}

// �г���ǰĿ¼�ļ�
void list_files() {
    const char* files[] = { "file1.txt", "file2.txt", "dir1", "dir2" };
    for (const char* file : files) { // ʹ�÷�Χ����ѭ��
        for (const char* c = file; *c != '\0'; c++) { // ��ӡ�ļ���
            asm("mov $0x0E, %%ah;"
                "mov %0, %%al;"
                "int $0x10"
                :
            : "r" (*c)
                : "%ax");
        }
    }
}

// ��ȡ�ļ�����
void read_file(const char* filename, char* buffer, uint32_t size) {
    // ʵ�ֶ�ȡ�ļ��߼�
}

// д���ļ�����
void write_file(const char* filename, const char* data, uint32_t size) {
    // ʵ��д���ļ��߼�
}

// �����ļ�
void create_file(const char* filename) {
    // �ļ������߼�
}

// ɾ���ļ�
void delete_file(const char* filename) {
    // �ļ�ɾ���߼�
}

// USB��ʼ��
void init_usb() {
    // ʵ��USB�������ĳ�ʼ���߼�
}

// USB������
void usb_handler() {
    // ����USB�¼�
}

// ������Ⱥ���
void scheduler() {
    // �������ʵ��
}

// ����������
void create_task(void (*task)()) {
    // ʵ�����񴴽��߼�
}

// ɾ������
void delete_task(int pid) {
    // ʵ������ɾ���߼�
}

// ����IDT��Ŀ
void set_idt_entry(int interrupt_number, void (*handler)()) {
    // ����IDT���߼�
}

// תȦ��������
void loading_animation() {
    const char* spinner = "-\\|/";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            asm("mov $0x0E, %%ah;"
                "mov %0, %%al;"
                "int $0x10"
                :
            : "r" (spinner[j])
                : "%ax");
            for (volatile int k = 0; k < 100000; k++); // �ӳٿ���
        }
    }
}

// �ں���ڵ�
void main() {
    const char* str = "Hello, Kernel!";
    for (const char* c = str; *c != '\0'; c++) { // ʹ�÷�Χ����ѭ��
        asm("mov $0x0E, %%ah;"
            "mov %0, %%al;"
            "int $0x10"
            :
        : "r" (*c)
            : "%ax");
    }

    // ��ʼ������USB����
    init_mouse();
    init_usb();

    // �г���ǰ�ļ�
    list_files();

    // ����תȦ����
    loading_animation();

    while (1);
}

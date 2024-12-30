#pragma once

#include <stdint.h> // ������׼��������

// ���״̬
extern volatile uint8_t mouse_buttons;
extern volatile int8_t mouse_x, mouse_y;

// ���������������
uint8_t inb(uint16_t port);                           // �Ӷ˿ڶ�ȡһ���ֽ�
void outb(uint16_t port, uint8_t value);             // ��˿�д��һ���ֽ�

// ��깦�ܺ���
void init_mouse();                                    // ��ʼ�����
void mouse_handler();                                 // ����¼�����

// �ļ�ϵͳ��������
void list_files();                                    // �г������ļ�
void read_file(const char* filename, char* buffer, uint32_t size); // ��ȡ�ļ�����
void write_file(const char* filename, const char* data, uint32_t size); // д���ļ�����
void create_file(const char* filename);              // �������ļ�
void delete_file(const char* filename);              // ɾ���ļ�

// USB��������
void init_usb();                                      // ��ʼ��USB�豸
void usb_handler();                                   // USB�¼�����

// ������������
void loading_animation();                              // չʾ��������

// ���������غ���
void scheduler();                                     // ��������߼�
void create_task(void (*task)());                     // ����������
void delete_task(int pid);                            // ɾ��ָ������

// �ж���������(IDT)���ú���
void set_idt_entry(int interrupt_number, void (*handler)()); // ����IDT��Ŀ

// �ں���ڵ㺯��
void main();                                          // ���ں˺�������

#pragma once

#include <stdint.h> // 包含标准整数类型

// 鼠标状态
extern volatile uint8_t mouse_buttons;
extern volatile int8_t mouse_x, mouse_y;

// 输入输出操作函数
uint8_t inb(uint16_t port);                           // 从端口读取一个字节
void outb(uint16_t port, uint8_t value);             // 向端口写入一个字节

// 鼠标功能函数
void init_mouse();                                    // 初始化鼠标
void mouse_handler();                                 // 鼠标事件处理

// 文件系统操作函数
void list_files();                                    // 列出所有文件
void read_file(const char* filename, char* buffer, uint32_t size); // 读取文件内容
void write_file(const char* filename, const char* data, uint32_t size); // 写入文件内容
void create_file(const char* filename);              // 创建新文件
void delete_file(const char* filename);              // 删除文件

// USB操作函数
void init_usb();                                      // 初始化USB设备
void usb_handler();                                   // USB事件处理

// 开机动画函数
void loading_animation();                              // 展示开机动画

// 任务调度相关函数
void scheduler();                                     // 任务调度逻辑
void create_task(void (*task)());                     // 创建新任务
void delete_task(int pid);                            // 删除指定任务

// 中断描述符表(IDT)设置函数
void set_idt_entry(int interrupt_number, void (*handler)()); // 设置IDT条目

// 内核入口点函数
void main();                                          // 主内核函数声明

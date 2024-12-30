#ifndef EXPLORER_H
#define EXPLORER_H

#include <stddef.h> // 引入stddef.h，以便使用size_t

// 结构体定义
typedef struct {
    char name[50];
    int age;
    float experience;
} Explorer;

// 函数声明
void initializeExplorer(Explorer* exp, const char* name, int age, float experience);
void displayExplorer(const Explorer* exp);
void explore(const Explorer* exp);

#endif // EXPLORER_H

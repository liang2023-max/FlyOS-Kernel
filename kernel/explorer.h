#ifndef EXPLORER_H
#define EXPLORER_H

#include <stddef.h> // ����stddef.h���Ա�ʹ��size_t

// �ṹ�嶨��
typedef struct {
    char name[50];
    int age;
    float experience;
} Explorer;

// ��������
void initializeExplorer(Explorer* exp, const char* name, int age, float experience);
void displayExplorer(const Explorer* exp);
void explore(const Explorer* exp);

#endif // EXPLORER_H

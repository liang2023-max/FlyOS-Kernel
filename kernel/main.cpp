#include "explorer.h" // �����ļ�ϵͳͷ�ļ�
#include <iostream>

void create_and_write_file(FileSystem& fs, const std::string& filename, const std::string& content) {
    fs.create_file(filename);
    fs.write_file(filename, content.c_str(), content.size()); // ʹ�� c_str() ת��Ϊ C �ַ���
}

void read_file_content(FileSystem& fs, const std::string& filename) {
    char buffer[256]; // �ٶ������и�����������ȡ����
    fs.read_file(filename, buffer, sizeof(buffer)); // �ٶ��˺���ʵ��
    std::cout << "���ݶ�ȡ���: " << buffer << std::endl; // �����ȡ������
}

void delete_file_and_list(FileSystem& fs, const std::string& filename) {
    fs.delete_file(filename);
    fs.list_files(); // �г���ǰ�ļ�
}

int main() {
    FileSystem fs; // �����ļ�ϵͳ����

    // ������д���ļ�
    create_and_write_file(fs, "example.txt", "Hello, world!");
    create_and_write_file(fs, "test.txt", "Test file content");

    // �г���ǰ�ļ�
    fs.list_files();

    // ��ȡ�ļ�����
    read_file_content(fs, "example.txt");

    // ɾ���ļ����г��ļ�
    delete_file_and_list(fs, "example.txt");
    delete_file_and_list(fs, "test.txt");

    return 0;
}

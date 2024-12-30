#include <iostream>
#include <cstring>
#include <cstdint>
#include <vector> // ʹ�ö�̬����

#define MAX_FILES 100

// �ļ��ṹ�嶨��
struct File {
    std::string name; // ʹ�� std::string ���� char ����
    uint32_t size;
};

// �ļ�ϵͳģ��
class FileSystem {
private:
    std::vector<File> files; // ʹ�ö�̬����洢�ļ�

public:
    FileSystem() {}

    void create_file(const std::string& filename) {
        if (files.size() < MAX_FILES) {
            files.push_back({ filename, 0 }); // ����ļ������ô�СΪ0
        }
        else {
            std::cout << "File limit reached!" << std::endl;
        }
    }

    void list_files() const {
        for (const auto& file : files) { // ʹ�÷�Χ for ѭ��
            std::cout << "File: " << file.name << ", Size: " << file.size << " bytes" << std::endl;
        }
    }

    void delete_file(const std::string& filename) {
        auto it = std::remove_if(files.begin(), files.end(),
            [&filename](const File& file) { return file.name == filename; }); // ʹ�� std::remove_if ���Ҳ�ɾ���ļ�

        if (it != files.end()) {
            files.erase(it, files.end()); // ɾ���ҵ����ļ�
            std::cout << "Deleted file: " << filename << std::endl;
        }
        else {
            std::cout << "File not found!" << std::endl;
        }
    }
};

// ������
int main() {
    FileSystem fs;
    fs.create_file("example.txt");
    fs.list_files();
    fs.delete_file("example.txt");
    fs.list_files();

    return 0;
}

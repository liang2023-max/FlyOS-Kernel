#include <iostream>
#include <cstring>
#include <cstdint>
#include <vector> // 使用动态数组

#define MAX_FILES 100

// 文件结构体定义
struct File {
    std::string name; // 使用 std::string 代替 char 数组
    uint32_t size;
};

// 文件系统模拟
class FileSystem {
private:
    std::vector<File> files; // 使用动态数组存储文件

public:
    FileSystem() {}

    void create_file(const std::string& filename) {
        if (files.size() < MAX_FILES) {
            files.push_back({ filename, 0 }); // 添加文件并设置大小为0
        }
        else {
            std::cout << "File limit reached!" << std::endl;
        }
    }

    void list_files() const {
        for (const auto& file : files) { // 使用范围 for 循环
            std::cout << "File: " << file.name << ", Size: " << file.size << " bytes" << std::endl;
        }
    }

    void delete_file(const std::string& filename) {
        auto it = std::remove_if(files.begin(), files.end(),
            [&filename](const File& file) { return file.name == filename; }); // 使用 std::remove_if 查找并删除文件

        if (it != files.end()) {
            files.erase(it, files.end()); // 删除找到的文件
            std::cout << "Deleted file: " << filename << std::endl;
        }
        else {
            std::cout << "File not found!" << std::endl;
        }
    }
};

// 主函数
int main() {
    FileSystem fs;
    fs.create_file("example.txt");
    fs.list_files();
    fs.delete_file("example.txt");
    fs.list_files();

    return 0;
}

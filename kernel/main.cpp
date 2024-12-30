#include "explorer.h" // 包含文件系统头文件
#include <iostream>

void create_and_write_file(FileSystem& fs, const std::string& filename, const std::string& content) {
    fs.create_file(filename);
    fs.write_file(filename, content.c_str(), content.size()); // 使用 c_str() 转换为 C 字符串
}

void read_file_content(FileSystem& fs, const std::string& filename) {
    char buffer[256]; // 假定我们有个缓冲区来读取内容
    fs.read_file(filename, buffer, sizeof(buffer)); // 假定此函数实现
    std::cout << "内容读取完毕: " << buffer << std::endl; // 输出读取的内容
}

void delete_file_and_list(FileSystem& fs, const std::string& filename) {
    fs.delete_file(filename);
    fs.list_files(); // 列出当前文件
}

int main() {
    FileSystem fs; // 创建文件系统对象

    // 创建并写入文件
    create_and_write_file(fs, "example.txt", "Hello, world!");
    create_and_write_file(fs, "test.txt", "Test file content");

    // 列出当前文件
    fs.list_files();

    // 读取文件内容
    read_file_content(fs, "example.txt");

    // 删除文件并列出文件
    delete_file_and_list(fs, "example.txt");
    delete_file_and_list(fs, "test.txt");

    return 0;
}

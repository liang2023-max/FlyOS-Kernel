#include <iostream>
#include <string>
#include <vector>
#include <optional>

#define MAX_FILES 100
#define INITIAL_SIZE 0

// 文件结构体定义
struct FileEntry {
    std::string name;
    uint32_t size;
};

// 文件系统模拟
class FileSystem {
private:
    std::vector<FileEntry> files;

public:
    std::optional<std::string> create_file(const std::string& filename) {
        if (files.size() < MAX_FILES) {
            files.push_back({ filename, INITIAL_SIZE });
            return std::nullopt; // 返回无错误
        }
        return "File limit reached!";
    }

    void list_files() const {
        if (files.empty()) {
            std::cout << "No files found!" << std::endl;
            return;
        }
        for (const auto& file : files) {
            std::cout << "File: " << file.name << ", Size: " << file.size << " bytes" << std::endl;
        }
    }

    std::optional<std::string> delete_file(const std::string& filename) {
        auto it = std::remove_if(files.begin(), files.end(),
            [&](const FileEntry& file) { return file.name == filename; });
        if (it != files.end()) {
            files.erase(it, files.end());
            return std::nullopt; // 返回无错误
        }
        return "File not found!";
    }
};

// 探险者结构体
struct Explorer {
    std::string name;
    int age;
    float experience;
};

// 函数实现
void initializeExplorer(Explorer& exp, const std::string& name, int age, float experience) {
    exp.name = name;
    exp.age = age;
    exp.experience = experience;
}

void displayExplorer(const Explorer& exp) {
    std::cout << "Name: " << exp.name << std::endl;
    std::cout << "Age: " << exp.age << std::endl;
    std::cout << "Experience: " << exp.experience << " years" << std::endl;
}

void explore(const Explorer& exp) {
    std::cout << exp.name << " is exploring the wilderness!" << std::endl;
}

// 主函数
int main() {
    // 测试文件系统
    FileSystem fs;
    if (auto error = fs.create_file("example.txt")) {
        std::cout << *error << std::endl;
    }
    fs.list_files();
    if (auto error = fs.delete_file("example.txt")) {
        std::cout << *error << std::endl;
    }
    fs.list_files();

    // 测试探险者
    Explorer exp;
    initializeExplorer(exp, "John", 30, 5.5);
    displayExplorer(exp);
    explore(exp);

    return 0;
}

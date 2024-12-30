#pragma once

#include <string>
#include <vector>
#include <memory>

class File {
public:
    File(const std::string& name, const std::string& path);

    void write(const std::string& data);
    std::string read() const;

private:
    std::string name;
    std::string path;
    std::string content;
};

class Directory {
public:
    Directory(const std::string& name);

    void addFile(const File& file);
    void addSubdirectory(const std::shared_ptr<Directory>& directory);
    std::shared_ptr<Directory> findSubdirectory(const std::string& name) const;

private:
    std::string name;
    std::vector<File> files;
    std::vector<std::shared_ptr<Directory>> subdirectories;
};

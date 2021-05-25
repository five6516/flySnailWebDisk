#pragma once

#include <vector>
#include <string>

typedef struct _FileInfo
{
    std::string fileName;
    std::string fullPath;
    bool isDir;
}FileInfo;


class FileAction
{
private:
    
public:
    FileAction(/* args */);
    ~FileAction();

    bool dirExists(const std::string& dirPath);
    bool fileExists(const std::string& filePath);
    bool makeDir(const std::string& dirPath);
    std::vector<FileInfo> listOfDir(const std::string& filePath,bool bIterate);
};




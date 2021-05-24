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

    std::vector<FileInfo> listOfDir(const std::string& filePath,bool bIterate);
};




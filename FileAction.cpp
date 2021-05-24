#include "FileAction.h"
#include <filesystem>

FileAction::FileAction(/* args */)
{
}

FileAction::~FileAction()
{
}

std::vector<FileInfo> FileAction::listOfDir(const std::string& filePath,bool bIterate)
{
    using namespace std;
    filesystem::path path(filePath);
    if(!filesystem::exists(path))
        return std::vector<FileInfo>();

    /* file */
    if(!filesystem::is_directory(path))
    {
        FileInfo fInfo;
        fInfo.fullPath = filePath;
        fInfo.fileName = filePath.substr(filePath.find_last_of("/")+1, filePath.size()-2 - filePath.find_last_of("/"));
        fInfo.isDir = false;
        return { fInfo };
    }

    /* dir */
    std::vector<FileInfo> dir_list;
    if(bIterate)
    {
        filesystem::recursive_directory_iterator it_dir(path);
        for (auto it : it_dir)
        {
            FileInfo fInfo;
            fInfo.fullPath = it.path().string();
            fInfo.fileName = it.path().filename().string();
            fInfo.isDir = it.is_directory();
            dir_list.emplace_back(fInfo);
        }
    }
    else
    {
        filesystem::directory_iterator it_dir(path);
        for (auto it : it_dir)
        {
            FileInfo fInfo;
            fInfo.fullPath = it.path().string();
            fInfo.fileName = it.path().filename().string();
            fInfo.isDir = it.is_directory();
            dir_list.emplace_back(fInfo);
        }
    } 
    return dir_list;
}
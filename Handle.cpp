#include "Handle.h"
#include "Render.h"
#include "FileAction.h"
#include "default_index.h"
#include <iostream>

Handle::Handle(httplib::Server* svr):m_pServer(svr)
{
    
}

Handle::~Handle()
{
}

int Handle::registerCallBack()
{
    m_pServer->set_mount_point("/ResDir", "./ResDir");
    m_pServer->Get("/",std::bind(&Handle::IndexView,this,std::placeholders::_1,std::placeholders::_2));
    //m_pServer->Get(R"(/ResDir/((\w+)(/*))*\.\w+)",std::bind(&Handle::loadFile,this,std::placeholders::_1,std::placeholders::_2));
    m_pServer->Get(R"(/ResDir/((\w+)(/*))*)",std::bind(&Handle::ListFile,this,std::placeholders::_1,std::placeholders::_2));
    std::function<void(const Request&, Response&)> upF= std::bind(&Handle::UpLoadFile, this, std::placeholders::_1, std::placeholders::_2);
    m_pServer->Post("/post", upF);  
    
    return 0;
}

void Handle::IndexView(const Request & request, Response & response)
{
    FileAction fileaction;
    std::vector<FileInfo> filelist = fileaction.listOfDir("./ResDir", false);

    Json listData;
    for (size_t i = 0; i < filelist.size(); i++)
    {
        Json data;
        data["fileName"] = filelist[i].fileName;
        data["fullPath"] = filelist[i].fullPath.substr(1, filelist[i].fullPath.size() - 1);
        data["isDir"] = filelist[i].isDir;

        listData["filelist"].push_back(data);
    }

    if(!fileaction.fileExists("./ResDir/index.html"))
        response.set_content(Render::render_string(strDefaultIndex,listData),"text/html");
    else
        response.set_content(Render::render_file("index.html",listData),"text/html");
}

void Handle::ListFile(const Request & request, Response & response)
{
    FileAction fileaction;
    std::vector<FileInfo> filelist = fileaction.listOfDir("." + request.path, false);

    Json listData;
    for (size_t i = 0; i < filelist.size(); i++)
    {
        Json data;
        data["fileName"] = filelist[i].fileName;
        data["fullPath"] = filelist[i].fullPath.substr(1, filelist[i].fullPath.size() - 1);
        data["isDir"] = filelist[i].isDir;

        listData["filelist"].push_back(data);
    }

    if(!fileaction.fileExists("./ResDir/index.html"))
        response.set_content(Render::render_string(strDefaultIndex,listData),"text/html");
    else
        response.set_content(Render::render_file("index.html",listData),"text/html");
}

void Handle::UpLoadFile(const Request& request, Response& response)
{
    const std::string resDir = "./ResDir";

    FileAction fileaction;
    if(!fileaction.dirExists(resDir))
        fileaction.makeDir(resDir);

    auto file = request.get_file_value("file");

    std::cout << "file length: " << file.content.length() << std::endl
        << "file name: " << file.filename << std::endl;

        std::ofstream ofs(resDir + "/"+ file.filename, std::ios::binary);
        ofs << file.content;

    //response.set_redirect("/");
}
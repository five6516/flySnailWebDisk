#pragma once
#include "httplib.h"

using namespace httplib;
class Handle
{
private:
    httplib::Server* m_pServer;

public:
    Handle(httplib::Server* svr);
    ~Handle();

    int registerCallBack();

    void IndexView(const Request & request, Response & response);
    void ListFile(const Request & request, Response & response);
    void UpLoadFile(const Request& request, Response& response);
};



#include <iostream>
#include <memory>
#include "httplib.h"
#include "Handle.h"

using namespace httplib;
int main(int argc, char* argv[])
{
    httplib::Server svr;
    std::unique_ptr<Handle> pHandle(new Handle(&svr));
    pHandle->registerCallBack();

    int port = 8888;
    std::cout << "start listen:" << port << std::endl;
    svr.listen("0.0.0.0",port);

    return 0;
}
#include "webserver.h"
#include "config.h"

int main(int argc, char *argv[])
{
    //命令行解析
    Config config;
    config.parse_arg(argc, argv);
    WebServer server(config);
    //日志
    server.log_write();

    //数据库
    server.sql_pool();

    //线程池
    server.thread_pool();

    //监听
    server.eventListen();

    //运行
    server.eventLoop();

    return 0;
}

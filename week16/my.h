#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/ioctl.h>


#define BACKLOG 4   	/*最大同时连接请求数*/
#define MAXDATASIZE 256
#define SERVPORT 4444		/*服务器监听端口号*/
#define MAXDATASIZE 256 	/*最大同时连接请求数*/
#define STDIN 0				/*标准输入文件描述符*/

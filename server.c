#include "common.h"

int main()
{
  // 1、创建管道
  umask(0);
  if(mkfifo(PIPE_NAME, 0664) == -1)
  {
    perror("mkfifo error\n");
    return 1;
  }
  // 2、以只读方式打开管道
  int fd = open(PIPE_NAME, O_RDONLY);
  if(fd == -1)
  {
    perror("server open reero\n");
    return 2;
  }
  // 3、从管道中读取数据
  char buf[64] = {0};
  while(1)
  {
    ssize_t len = read(fd, buf, sizeof(buf) - 1);
    if(len > 0)
    {
      buf[len] = 0;
      printf("server receive]: %s", buf);
      buf[0] = 0;
    }
    else if(len == 0)
    {
      printf("******* client end *******\n");
      break;
    }
    else 
    {
      perror("server read error\n");
      return 3;
    }
  }
  return 0;
}

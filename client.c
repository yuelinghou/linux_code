#include "common.h"

int main()
{
  // 1、以只写方式打开管道
  int fd = open(PIPE_NAME, O_WRONLY);
  if(fd == -1)
  {
    perror("client open error\n");
    return 1;
  }
  // 2、读取标准输入的数据，把这些数据写到管道中
  char buf[64] = {0};
  while(1)
  {
    printf("[client input]: ");
    fflush(stdout);
    ssize_t len = read(0, buf, sizeof(buf));
    if(len > 0)
    {
      write(fd, buf, len);
      buf[0] = 0;
    }
    else 
    {
      perror("client read error\n");
      return 2;
    }
  }
  return 0;
}

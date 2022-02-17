#include "common.h"

int main()
{
  // 1、ftok获得唯一的key键值
  key_t key = ftok(PATH, PROJ_ID);
  if(key == -1)
  {
    perror("ftok error\n");
  }
  // 2、shmget得到已存在共享内存对象的标识符ID
  int shmid = shmget(key, SIZE, 0);
  if(shmid == -1)
  {
    perror("shmget error\n");
  }
  // 3、shmat把进程和共享内存挂接 
  void* shmaddr = shmat(shmid, NULL, 0);
  if(shmaddr == (void*)-1)
  {
    perror("shmat error\n");
  }
  // 4、client端向共享内存对象写入数据
  const char* str = "i am process A";
  strcpy((char*)shmaddr, str);
  // 5、shmdt取消进程与共享内存之间的挂接
  if(shmdt(shmaddr) == -1)
  {
    perror("shmdt error\n");
  }
  return 0;
}

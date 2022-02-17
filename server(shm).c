#include "common.h"

int main()
{
  // 1、ftok获得唯一的key键值
  key_t key = ftok(PATH, PROJ_ID);
  if(key == -1)
  {
    perror("ftok error\n");
  }
  // 2、shmget创建一个全新的共享内存对象
  int shmid = shmget(key, SIZE, 0664|IPC_CREAT|IPC_EXCL);
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
  // 4、读取共享内存对象当中的数据
  int i = 0;
  for(i = 0; i < 10; ++i)
  {
    printf("server:%s\n", (char*)shmaddr);
    sleep(1);
  }
  // 5、shmdt取消进程与共享内存之间的挂接
  if(shmdt(shmaddr) == -1)
  {
    perror("shmdt error\n");
  }
  // 6、shmctl释放共享内存空间
  shmctl(shmid, IPC_RMID, NULL);
  return 0;
}

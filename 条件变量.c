#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void* Routine(void* arg)
{
  pthread_detach(pthread_self());
  while(1)
  {
    pthread_cond_wait(&cond, &mutex);
    printf("I am thread %d，runing\n", (int)arg);
  }
}

int main()
{
  // 1、初始化全局的互斥锁和条件变量
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
  // 2、创建4个新线程
  pthread_t tids[4];
  for(int i = 0; i < 4; ++i)
  {
    pthread_create(&tids[i], NULL, Routine, (void*)(i + 1));
  }
  // 3、每输入一个回车唤醒一个条件等待队列里的线程
  while(1)
  {
    getchar();
    pthread_cond_signal(&cond);
  }
  // 4、销毁互斥锁和条件变量
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond);
  return 0;
}

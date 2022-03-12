//#include <stdio.h>
//#include <unistd.h>
//#include <pthread.h>
//
//int count = 10;
//
//void* GetTickets(void* arg)
//{
//  while(1)
//  {
//    if(count > 0)
//    {
//      // 睡眠10000毫秒，模拟买票时的流程（访问数据库，更新数据库等等）
//      usleep(10000);
//      // 买到了一张票
//      printf("[thread %d] get ticket No.%d\n", (int)arg, count);
//      --count;
//    }
//    else 
//    {
//      break;
//    }
//  }
//}
//
//int main()
//{
//  // 1、创建4个新线程
//  pthread_t tids[4];
//  for(int i = 0; i < 4; ++i)
//  {
//    pthread_create(&tids[i], NULL, GetTickets, (void*)(i+1));
//  }
//  // 2、阻塞等待4个新线程把票抢完
//  for(int i = 0; i < 4; ++i)
//  {
//    pthread_join(tids[i], NULL);
//  }
//  return 0;
//}


//#include <stdio.h>
//#include <unistd.h>
//#include <pthread.h>
//
//int count = 1000;
//pthread_mutex_t mutex;
//
//void* GetTickets(void* arg)
//{
//  while(1)
//  {
//    pthread_mutex_lock(&mutex);
//    if(count > 0)
//    {
//      usleep(2000);
//      printf("[thread %d] get ticket No.%d\n", (int)arg, count);
//      --count;
//      pthread_mutex_unlock(&mutex);
//      usleep(10);
//    }
//    else 
//    {
//      pthread_mutex_unlock(&mutex);
//      break;
//    }
//  }
//}
//
//int main()
//{
//  // 1、创建新线程之前先把锁初始化
//  pthread_mutex_init(&mutex, NULL);
//  // 2、创建4个新线程
//  pthread_t tids[4];
//  for(int i = 0; i < 4; ++i)
//  {
//    pthread_create(&tids[i], NULL, GetTickets, (void*)(i+1));
//  }
//  // 3、阻塞等待4个新线程把票抢完
//  for(int i = 0; i < 4; ++i)
//  {
//    pthread_join(tids[i], NULL);
//  }
//  // 4、等待新线程把票抢完后释放锁
//  pthread_mutex_destroy(&mutex);
//  return 0;
//}

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void* Routine(void* arg)
{
  // 1、申请锁
  pthread_mutex_lock(&mutex);
  // 2、执行10次打印，并且自己重复申请锁
  for(int i = 0; i < 10; ++i)
  {
    printf("I am new thread，runing\n");
    pthread_mutex_lock(&mutex);
  }
  // 3、释放锁
  pthread_mutex_unlock(&mutex);
  // 4、新线程退出
  pthread_exit(NULL);
}

int main()
{
  // 1、创建新线程之前初始化锁
  pthread_mutex_init(&mutex, NULL);
  // 2、创建新线程
  pthread_t tid;
  pthread_create(&tid, NULL, Routine, NULL);
  // 3、阻塞等待新线程结束
  pthread_join(tid, NULL);
  // 4、销毁锁
  pthread_mutex_destroy(&mutex);
  return 0;
}





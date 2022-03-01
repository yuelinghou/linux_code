//#include <stdio.h>
//#include <sys/types.h>
//#include <unistd.h>
//
//int main()
//{
//  while(1)
//  {
//    printf("Im pid is:%d\n", getpid());
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//
//void Handler(int signo)
//{
//  printf("  receive signal:%d\n", signo);
//}
//
//int main()
//{
//  signal(9, Handler);
//  signal(19, Handler);
//  raise(19);
//  while(1)
//  {
//    printf("I am runing\n");
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//  printf("*****begin*****\n");
//  int* p = NULL;
//  *p = 100;
//  printf("***** end *****\n");
//  return 0;
//}

//#include <stdio.h>
//#include <signal.h>
//
//void Handler(int signo)
//{
//  printf("  receive signal:%d\n", signo);
//}
//
//int main()
//{
//  for(int i = 0; i <= 31; ++i)
//  {
//    signal(i, Handler);
//  }
//  while(1)
//  {}
//  return 0;
//}


//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//
//int main()
//{
//  while(1)
//  {
//    printf("Im pid is:%d\n", getpid());
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//#include <unistd.h>
//
//int main()
//{
//  pid_t id = fork();
//  if(id == 0) //chiled
//  {
//    int* p = NULL;
//    *p = 100;
//  }
//  else if(id > 0) //father
//  {
//    int status = 0;
//    if(waitpid(-1, &status, 0) == -1)
//    {
//      perror("waitpid error\n");
//    }
//    else 
//    {
//      printf("core_dump:%d，signal:%d\n", (status>>7) & 1, status & 0x7f);
//    }
//  }
//  else 
//  {
//    perror("fork error\n");
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <sys/types.h>
//#include <stdlib.h>
//#include <signal.h>
//
//int main(int argc, char* argv[])
//{
//  // 解析命令行参数
//  int signo = atoi(argv[1] + 1); 
//  pid_t pid = atoi(argv[2]);
//  // 根据解析得到的结果调用kill函数
//  kill(pid, signo);
//  return 0;
//}

//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//
//void Handler(int signo)
//{
//  printf("receive signo：%d\n", signo);
//}
//
//int main()
//{
//  // 1、自定义处理收到了得2号信号
//  signal(2, Handler);
//  // 2、使用raise每秒给自己发送一个2号信号
//  while(1)
//  {
//    if(raise(2) == -1)
//    {
//      perror("raise error\n");
//      return 1;
//    }
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <signal.h>
//
//void Handler(int signo)
//{
//  printf("recieve signo：%d\n", signo);
//  exit(1);
//}
//
//int main()
//{
//  signal(6, Handler);
//  abort();
//  return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//int main()
//{
//  // 1、创建一个匿名管道
//  int fd[2] = {0};
//  if(pipe(fd) == -1)
//  {
//    perror("pipe error\n");
//    return 1;
//  }
//  pid_t id = fork();
//  // 2、子进程向管道写入数据，父进程把读端关闭导致子进程收到SIGPIPE(13)信号
//  if(id == 0) //child
//  {
//    close(fd[0]);
//    const char* str = "hello Linux\n";
//    while(1)
//    {
//      write(fd[1], str, strlen(str));
//      sleep(1);
//    }
//  }
//  else if(id > 0) //father
//  {
//    close(fd[0]);
//    close(fd[1]);
//    int status = 0;
//    waitpid(-1, &status, 0);;
//    printf("child exit，recieve signal：%d\n", status & 0x7f);
//  }
//  else 
//  {
//    perror("fork error\n");
//    return 2;
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <unistd.h>
//
//int main()
//{
//  alarm(5);
//  int count = 0;
//  while(1)
//  {
//    printf("count = %d\n", count++);
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <signal.h>
//
//void Handler(int signo)
//{
//  printf("reveive signal：%d\n", signo);
//  exit(1);
//}
//
//int main()
//{
//  signal(11, Handler);
//  printf("***** begin *****\n");
//  int* p = NULL;
//  *p = 100;
//  printf("*****  end  *****\n");
//  return 0;;
//}

//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <signal.h>
//
//void PrintfSet(const sigset_t set)
//{
//  for(size_t i = 1; i <= 31; ++i)
//  {
//    int ret = sigismember(&set, i);
//    if(ret == 1)// 包含返回1
//    {
//      printf("1 ");
//    }
//    else if(ret == 0)// 不包含返回0
//    {
//      printf("0 ");
//    }
//    else// 调用出错返回-1
//    {
//      perror("sigismember error\n");
//      exit(1);
//    }
//  }
//  printf("\n");
//}
//
//int main()
//{
//  // 1、建立一个set类型的变量
//  sigset_t pending_set;
//  sigemptyset(&pending_set);
//  // 2、读取当前进程的未决信号集
//  sigpending(&pending_set);
//  // 3、以位图的方式模拟打印未决信号集
//  PrintfSet(pending_set);
//  return 0;
//}


//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <signal.h>
//
//void PrintfSet(const sigset_t set)
//{
//  for(int i = 1; i <= 31; ++i)
//  {
//    int ret = sigismember(&set, i);
//    if(ret == 1)// 包含返回1
//    {
//      printf("1 ");
//    }
//    else if(ret == 0)// 不包含返回0
//    {
//      printf("0 ");
//    }
//    else// 调用出错返回-1
//    {
//      perror("sigismember error\n");
//      exit(1);
//    }
//  }
//  printf("\n");
//}
//
//void Handler(int signo)
//{
//  printf("handler signal：%d\n", signo);
//}
//
//int main()
//{
//  // 自定义处理2号信号
//  signal(2, Handler);
//  // 1、把阻塞信号集中的2号信号置为"有效"
//  sigset_t blocked_set;
//  sigemptyset(&blocked_set);
//  sigaddset(&blocked_set, 2);
//  sigprocmask(SIG_BLOCK, &blocked_set, NULL);
//  printf("blocked set signal：2\n");
//  // 2、不断打印进程的未决信号集
//  int count = 0;
//  sigset_t pending_set;
//  while(1)
//  {
//    sigemptyset(&pending_set);
//    sigpending(&pending_set);
//    PrintfSet(pending_set);
//    ++count;
//    sleep(1);
//    if(count == 2)// 向自己发送2号信号
//    {
//      raise(2);
//      printf("pending set signal：2\n");
//    }
//    else if(count == 4)// 把阻塞信号集中的2号信号置为"无效"
//    {
//      sigprocmask(SIG_UNBLOCK, &blocked_set, NULL);
//      printf("blocked no signal：2\n");
//    }
//  }
//}

//#include <stdio.h>
//#include <signal.h>
//#include <unistd.h>
//
//struct sigaction act, oact;
//
//// 在自定义处理函数中恢复对2号信号原来的处理动作（即默认处理动作）
//void Handler(int signo)
//{
//  printf("  handler signal：%d\n", signo);
//  sigaction(2, &oact, NULL);
//  printf("recover signal：2\n");
//}
//
//int main()
//{
//  // 1、对sigaction的第二个参数的成员进行初始化（主要设置了一个自定义捕捉函数）
//  act.sa_handler = Handler;
//  sigemptyset(&act.sa_mask);
//  act.sa_restorer = NULL;
//  act.sa_flags = 0;
//  // 2、调用sigaction函数来自定义处理2号信号
//  sigaction(2, &act, &oact);
//  // 3、死循环打印一句话
//  while(1)
//  {
//    printf("I am runing\n");
//    sleep(1);
//  }
//  return 0;
//}

//#include <stdio.h>
//#include <signal.h>
//
//volatile int flag = 0;
//
//void Handler(int signo)
//{
//  flag = 1;
//  printf("  flag already set to 1\n");
//}
//
//int main()
//{
//  signal(2, Handler);
//  while(!flag)
//  {}
//  printf("process ending\n");
//  return 0;
//}

//#include <stdio.h>
//#include <signal.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//void Handler(int signo)
//{
//  pid_t pid;
//  int status;
//  while((pid = waitpid(0, &status, WNOHANG)) > 0)
//  {
//    printf("-----------------child pid is：%d, exit code is：%d\n", pid, (status>>8) & 0x7f);
//    sleep(1);
//  }
//}
//
//int main()
//{
//  int i ;
//  pid_t id;
//  for(i = 0; i < 10; ++i)// 创建10个子进程
//  {
//    id = fork();
//  }
//  
//  if(id == 0)// child
//  {
//    printf("I am %d child，pid is：%d\n", i + 1, getpid());
//    sleep(1);
//    return i + 1;
//  }
//  else if(id > 0)// father
//  {
//    // 1、父进程主执行流一开始就先把SIGCHLD阻塞
//    sigset_t set, oset;
//    sigemptyset(&set);
//    sigemptyset(&oset);
//    sigaddset(&set, 17);
//    sigprocmask(SIG_BLOCK, &set, &oset);
//    // 2、自定义捕捉子进程终止时向父进程发送的17号信号
//    signal(17, Handler);
//    // 3、设置完SIGCHLD信号的信号捕捉函数之后再解除对该信号的阻塞
//    sigprocmask(SIG_SETMASK, &oset, NULL);
//    // 4、父进程等待接收SIGCHLD信号
//    for(int count = 0; count < 10; ++count)
//    {
//      printf("parent pid is：%d\n", getpid());
//      sleep(1);
//    }
//  }
//  return 0;
//}

#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
void sys_err(char* str)
{
    perror(str);
    exit(1);
}

void Handler(int signo)
{
  int status;
  pid_t pid;
   
  while ((pid = waitpid(0, &status, WNOHANG)) > 0)
  {
   if (WIFEXITED(status))
       printf("---------------------------child %d exit %d\n", pid, WEXITSTATUS(status));
   else if (WIFSIGNALED(status))
       printf("child %d cancel signal %d\n", pid, WTERMSIG(status));
  }
}
 
int main()
{
  pid_t pid;
  int i;
  for (i = 0; i < 10; i++)
  {
    if ((pid = fork()) == 0)
            break;
        else if (pid < 0)
            sys_err("fork");
  }
  if (pid == 0) //子进程
  {
   int n = 1;
   while (n--)
   {
       printf("child ID %d\n", getpid());
       sleep(1);
   }
   return i + 1;
  }
  else if (pid > 0) //父进程
  {
    // 1、父进程主执行流一开始就先把SIGCHLD阻塞
    sigset_t set, oset;
    sigemptyset(&set);
    sigemptyset(&oset);
    sigaddset(&set, 17);
    sigprocmask(SIG_BLOCK, &set, &oset); 
    // 2、自定义捕捉子进程终止时向父进程发送的17号信号
    struct sigaction act;        
    act.sa_handler = Handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, NULL);    
    // 3、设置完SIGCHLD信号的信号捕捉函数之后再解除对该信号的阻塞
    sigprocmask(SIG_SETMASK, &oset, NULL);
    // 4、父进程等待接收SIGCHLD信号
    while (1)
    {
        printf("parent ID %d\n", getpid());
        sleep(1);
    }
  }
  return 0;
}

//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//#include <sys/types.h>
//#include <sys/wait.h>
//
//void Handler(int signo)
//{
//  printf("No.%d receive siganl：%d\n", getpid(), signo);
//}
//
//int main()
//{
//  signal(17, Handler);
//  pid_t id = fork();
//  if(id == 0)// child
//  {
//    printf("I am child，pid is：%d，ppid is：%d\n", getpid(), getppid());
//    return 1;
//  }
//  waitpid(-1, NULL, 0);
//  return 0;
//}






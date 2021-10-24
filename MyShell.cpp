#include <iostream>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
  while(1)
  {
    // 获取命令行 + 解析命令行
    cout<<"[myshell]$ ";
    char* argList[20] = {nullptr};
    string s;
    string tmp;
    int i = 0;
    vector<string> v(20);
    // 1、获取一行命令行，存储在string类型对象s中
    getline(cin, s);
    // 2、遍历s，取出其中的每一个命令和选项，先放到数组v中，完成字符串内容的深拷贝
    // 在把每一个元素的指针存到指针数组argList里
    for(auto e : s)
    {
      if(e == ' ')
      {
        v[i] = tmp;
        argList[i] = (char*)v[i].c_str();
        ++i;
        tmp.clear();
      }
      else 
      {
        tmp += e;
      }
    }
    // 最后一个命令还没有存放，因为我们输入的一行字符串最后一个字符不是以空格结尾的
    argList[i] = (char*)tmp.c_str();
    // 3、父子进程分流完成各自的任务
    // 子进程：用execvp完成程序替换
    // 父进程：等待子进程
    pid_t id = fork();
    if(id == 0)// 子进程
    {
      execvp(argList[0], argList);
      exit(-1);
    }
    else if(id > 0)// 父进程
    {
      int status = 0;
      int ret = wait(&status);
      if(ret > 0)// a、等待成功
      {
        if(WIFEXITED(status))// 正常退出
        {
          cout<<"child exit code is："<<WEXITSTATUS(status)<<endl;
        }
        else// 异常退出
        {
          cout<<"abnormal exited"<<endl;
        }
      }
      else// b、等待失败
      {
        cout<<"wait fail"<<endl;
      }
    }
  }
  return 0;
}

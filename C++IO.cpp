#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
using namespace std;

//struct Person
//{
//  int _age;
//  string _name;
//};
//
//int main()
//{
//  Person p;
//  // C语言输入输出
//  scanf("%d%s",&p._age, (char*)p._name.c_str());
//  printf("年龄:%d 姓名:%s\n", p._age, p._name.c_str());
//  // C++输入输出
//  cin>>p._age>>p._name;
//  cout<<"年龄:"<<p._age<<" "<<"姓名:"<<p._name<<endl;
//}

//int main()
//{
//  string s;
//  // cin和cout输入输出 
//  cin>>s;
//  cout<<s<<endl;
//  cout<<"string对象的容量:"<<s.capacity()<<endl;
//  // 仅scanf输入
//  scanf("%s", (char*)s.c_str());
//  return 0;
//}

//int main()
//{
//  string s;
//  s.reserve(100);// 预留100字节空间
//  // 1、cin和cout输入输出
//  cin>>s;
//  cout<<s<<endl;
//  cout<<"string类对象的size为:"<<s.size();
//  // 2、scanf和printf出入输出
//  scanf("%s", (char*)s.c_str());
//  cout<<s;
//  return 0;
//}
//

//int main()
//{
//  string s1;
//  string s2;
//  getline(cin, s1); 
//  cout<<"s1："<<s1<<endl;
//  getline(cin, s2); 
//  cout<<"s2："<<s2<<endl;
//  return 0;
//}


//int main()
//{
//  cout<<"###################################";
//  sleep(3);
//  return 0;
//}

// C语言中的连续输入
//int main()
//{
//  char buff[100];
//  //也可以这样写：while(~scanf("%s", buff))
//  while((scanf("%s", buff)) != EOF)
//  {
//    printf("%s\n", buff);
//  }
//  return 0;
//}

//int main()
//{
//  string s;
//  while(cin>>s)
//  {
//    cout<<s<<endl;
//  }
//  return 0;
//}
//

//class A
//{};


//class A
//{
//  public:
//    operator void*()
//    {
//      cout<<"operator void*()"<<endl;
//      return (void*)this;
//    }
//};


//class A
//{
//  public:
//    operator void*()
//    {
//      cout<<"operator void*()"<<endl;
//      return (void*)0;
//    }
//
//    bool operator!()
//    {
//      cout<<"operator!()"<<endl;
//      return true;
//    }
//};
//
//
//int main()
//{
//  A a;
//  if(!a)
//  {
//    cout<<"Yes"<<endl;
//  }
//  return 0;
//}


//class A
//{
//  public:
//    operator void*()
//    {
//      if(_count<3)
//      {
//        cout<<"Yes"<<endl;
//        return (void*)this;
//      }
//      else 
//      {
//        cout<<"No"<<endl;
//        return (void*)0;
//      }
//    }
//
//    int _count=0;
//};
//
//int main()
//{
//  A a;
//  while(a)
//  {
//    ++a._count;
//  }
//  return 0;
//}

//void ReadFile()
//{
  //ifstream ifs("main.cpp");
  // 文本形式读取
  //char ch;
  //while(ifs.get(ch))
  //{
  //  cout<<ch;
  //}
  
  // 二级制形式读取
  //while(ifs)
  //{
  //  cout<<ifs.get();
  //}
//}

//void WriteFile()
//{
//  ofstream ofs("write.txt");
//  ofs.put('x');
//  ofs.write("hello world", 10);
//}
//
//int main()
//{
//  ReadFile();
//  WriteFile();
//  return 0;
//}




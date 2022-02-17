#pragma once 

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATH "/home/ljj/Linux_code/test_2022_2_15/System_V_IPC/shm"// 任意已存在的路径
#define PROJ_ID 3// 任意数字
#define SIZE 4096// 共享内存大小

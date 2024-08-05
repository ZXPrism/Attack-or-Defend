#pragma once
#ifdef _WIN32
// Windows
#include <Windows.h>
#define Clear() std::system("cls")
#define Change_code_to_utf8()  std::system("chcp 65001")
#else
// Linux
#include <unistd.h>
#define Sleep(x) usleep(x*1000)
#define Clear() std::system("clear")
#define Change_code_to_utf8()  
#endif

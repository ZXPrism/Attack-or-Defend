# Attack or Defend

My console game written in C++ 7 years ago.

*——谨以此项目纪念那一去不复返的童年。*

## Getting Started
（待施工）

## Requirements on PRs (Code Style)
请配合 [docs/Style.h](docs/Style.h) 食用。

### 杂项
- 按照本项目附带的 .clang-format 文件对代码进行格式化
- 每个文件末尾保留**一个**空行
- 使用 `#pragma once` 进行头文件保护

### 文件名
- 除 `main.cpp` 外，一律使用大驼峰命名，如 `ExampleFile.cpp`

### 变量名称
- 基本规则：`前缀（可选）` + `小驼峰命名`
- 一般变量：无前缀，如 `variableD`
- 全局变量：前缀 `g`，如 `gVariableA`
- 静态变量：前缀 `s`，如 `sVariableB`
- 成员变量：前缀 `_`，如 `_VariableC`
- 常量：全大写，用 `_` 分割语义，如 `CONSTANT_A`


### 函数名称（包括 Lambda 函数）
- 基本规则：`前缀（可选）` + `大驼峰命名`
- 一般函数：无前缀，如 `FunctionA`
- public 成员函数：同一般函数，如 `FunctionB`
- 其他成员函数：前缀 `_`，如 `_FunctionC`

### 类
- `大驼峰命名`，如 `ExampleClass`
- 成员变量和成员函数分别使用访问控制关键字，如：
```cpp
public:
    void MemberFunction1();

public:
    int _X;
    int _Y;

private:
    void _MemberFunction2();

private:
    int _VarA;
```

### 枚举
- `大驼峰命名`，并附加使用 `class` 关键字
- 如 `enum class ExampleEnum{};`

### 命名空间名称
- 基本规则：全小写，尽可能言简意赅，如 `aod`
- （应该不需要用到除 `std` 和 `aod` 以外的命名空间了）
- 在必要的地方（如 .cpp 文件中）可使用 `using namespace aod;` 以简化代码
- 不得使用 `using namespace std;`

### 注释
- 只在必要的地方使用注释，不滥用注释或写无意义的注释


### 宏
- 全大写，用 `_` 分割语义，如 `#define MY_PI 3.14159`


### 引用其他头文件
- 分为三类：本项目头文件、标准库头文件和系统头文件（递减顺序）
- 每一类头文件之间用空行分隔
- 如：
```cpp
#include "aod.h"

#include <iostream>

#include <Windows.h>
```

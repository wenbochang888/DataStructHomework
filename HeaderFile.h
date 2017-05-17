#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;

//定义字符串结构体最大为100
#define maxsize 100

//字符串结构体的栈
typedef struct chang
{
    string a[maxsize];
    int top;
} Stack;

//初始化栈
void InitStack(Stack &s);
//判断栈是否为空
bool isEmpty(Stack &s);
//返回栈顶元素
string getTop(Stack &s);
//将字符串e压入栈中
void pushStack(Stack &s, string e);
//将栈顶元素出栈
void PopStack(Stack &s);






//判断是否为操作符 +-*/^%
bool isOpr(char ch);

//重载isopr，同样判断是否为操作符 +-*/^%
bool isOpr(string ch);

//判断是否为左括号（
bool isZuoKuoHao(char ch);

//重载isZuoKuoHao，判断是否为左括号（
bool isZuoKuoHao(string ch);

//判断是否为右括号）
bool isYouKuoHao(char ch);

//重载isYouKuoHao，判断是否为左括号）
bool isYouKuoHao(string ch);

//判断栈顶符号的优先级是不是高于或者等于进栈符号的优先级
bool isHighOpr(string top, string in);

//将字符串转化为double类型的数字
double strChangeToDouble(string a);

//将double转化为string类型
string douChangeTostring(double a);

/*
*判断是不是数字
*是数字返回非零值，true，不是数字返回0，false。
*/
int isNumber(double d);

//判断是不是整数，是整数返回true，否则false
bool isZhengshu(double n);

//初始化strTemp这个字符串。如10+2.5 将10和2.5看成一个整体
void init(string strTemp, string strMid[]);

//文件输入输出流
void ioFstream();

//整个工程的重要部分，计算表达式。
void calOpr(string strTemp);













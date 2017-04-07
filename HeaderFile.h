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
using namespace std;

#define maxsize 100

typedef struct chang
{
    string a[maxsize];
    int top;
} Stack;


void InitStack(Stack &s);
bool isEmpty(Stack &s);
string getTop(Stack &s);
void pushStack(Stack &s, string e);
void PopStack(Stack &s);







//�ж��Ƿ�Ϊ������ +-*/^%
bool isOpr(char ch);

//����isopr��ͬ���ж��Ƿ�Ϊ������ +-*/^%
bool isOpr(string ch);

//�ж��Ƿ�Ϊ�����ţ�
bool isZuoKuoHao(char ch);

//����isZuoKuoHao���ж��Ƿ�Ϊ�����ţ�
bool isZuoKuoHao(string ch);

//�ж��Ƿ�Ϊ�����ţ�
bool isYouKuoHao(char ch);

//����isYouKuoHao���ж��Ƿ�Ϊ�����ţ�
bool isYouKuoHao(string ch);

//�ж�ջ�����ŵ����ȼ��ǲ��Ǹ��ڻ��ߵ��ڽ�ջ���ŵ����ȼ�
bool isHighOpr(string top, string in);

//���ַ���ת��Ϊdouble���͵�����
double strChangeToDouble(string a);

//��doubleת��Ϊstring����
string douChangeTostring(double a);

/*
*�ж��ǲ�������
*�����ַ��ط���ֵ��true���������ַ���0��false��
*/
int isNumber(double d);

//�ж��ǲ�������������������true������false
bool isZhengshu(double n);

//��ʼ��strTemp����ַ�������10+2.5 ��10��2.5����һ������
void init(string strTemp, string strMid[]);

//�ļ����������
void ioFstream();

//�������̵���Ҫ���֣�������ʽ��
void calOpr(string strTemp);













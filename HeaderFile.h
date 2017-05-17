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

//�����ַ����ṹ�����Ϊ100
#define maxsize 100

//�ַ����ṹ���ջ
typedef struct chang
{
    string a[maxsize];
    int top;
} Stack;

//��ʼ��ջ
void InitStack(Stack &s);
//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack &s);
//����ջ��Ԫ��
string getTop(Stack &s);
//���ַ���eѹ��ջ��
void pushStack(Stack &s, string e);
//��ջ��Ԫ�س�ջ
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













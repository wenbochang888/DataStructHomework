#include "HeaderFile.h"

//��ʼ��ջ
void InitStack(Stack &s)
{
    s.top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack &s)
{
    if(s.top == -1)
        return true;
    return false;
}

//���ջ��Ԫ�أ����Ϊ���򷵻�error
string getTop(Stack &s)
{
    if(!isEmpty(s))
    {
        return s.a[s.top];
    }
    return "error";
}

//��Ԫ��eѹ��ջ��
void pushStack(Stack &s, string e)
{
    if(s.top <= maxsize)
    {
        s.top++;
        s.a[s.top] = e;
    }
}

//��ջ��Ԫ�س�ջ
void PopStack(Stack &s)
{
	if(!isEmpty(s))
	{
		s.top--;
	}
}
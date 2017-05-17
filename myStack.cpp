#include "HeaderFile.h"

//初始化栈
void InitStack(Stack &s)
{
    s.top = -1;
}

//判断栈是否为空
bool isEmpty(Stack &s)
{
    if(s.top == -1)
        return true;
    return false;
}

//获得栈顶元素，如果为空则返回error
string getTop(Stack &s)
{
    if(!isEmpty(s))
    {
        return s.a[s.top];
    }
    return "error";
}

//将元素e压入栈顶
void pushStack(Stack &s, string e)
{
    if(s.top <= maxsize)
    {
        s.top++;
        s.a[s.top] = e;
    }
}

//将栈顶元素出栈
void PopStack(Stack &s)
{
	if(!isEmpty(s))
	{
		s.top--;
	}
}
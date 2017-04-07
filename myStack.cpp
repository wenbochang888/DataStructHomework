#include "HeaderFile.h"

void InitStack(Stack &s)
{
    s.top = -1;
}

bool isEmpty(Stack &s)
{
    if(s.top == -1)
        return true;
    return false;
}

string getTop(Stack &s)
{
    if(!isEmpty(s))
    {
        return s.a[s.top];
    }
    return "error";
}

void pushStack(Stack &s, string e)
{
    if(s.top <= maxsize)
    {
        s.top++;
        s.a[s.top] = e;
    }
}

void PopStack(Stack &s)
{
	if(!isEmpty(s))
	{
		s.top--;
	}
}
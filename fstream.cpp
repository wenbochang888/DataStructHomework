#include "HeaderFile.h"


void ioFstream()
{
	//重定向输入输出流
	//将从键盘输入改为从文件中读取
	//将从输出到控制台改为输出到文件
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


	//从文件中读取表达式，直到读到文件的末尾
    string expression;
    while(cin >> expression)
    {
        calOpr(expression);
    }

	//将从输出到文件改为输出到控制台
    freopen("CON","w",stdout);
}
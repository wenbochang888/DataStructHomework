#include "HeaderFile.h"

int main()
{
	//获取当前windows时间的函数
	time_t t = time(0);
    char tmp[64];
    strftime(tmp,sizeof(tmp),"%Y/%m/%d %X %A %z",localtime(&t));

	printf("                              欢迎进入表达式求值系统\n\n");
    printf("                              15计算机一班  常文博\n\n");
    printf("                     %s\n\n\n\n",tmp);
	//Sleep(2000);

	printf("                   -----------程序开始执行，请稍后-----------\n\n");
	//Sleep(1000);
	ioFstream();
	printf("                                 程序执行完毕\n\n");
    printf("                   请打开本目录下的output.txt文件查看运行结果\n\n");
	printf("                              欢迎您的使用，再见\n\n");
	//system("output.txt");

	return 0;
} 
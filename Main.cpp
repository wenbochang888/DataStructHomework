#include "HeaderFile.h"

int main()
{
	//��ȡ��ǰwindowsʱ��ĺ���
	time_t t = time(0);
    char tmp[64];
    strftime(tmp,sizeof(tmp),"%Y/%m/%d %X %A %z",localtime(&t));

	printf("                              ��ӭ������ʽ��ֵϵͳ\n\n");
    printf("                              15�����һ��  ���Ĳ�\n\n");
    printf("                     %s\n\n\n\n",tmp);
	//Sleep(2000);

	printf("                   -----------����ʼִ�У����Ժ�-----------\n\n");
	//Sleep(1000);
	ioFstream();
	printf("                                 ����ִ�����\n\n");
    printf("                   ��򿪱�Ŀ¼�µ�output.txt�ļ��鿴���н��\n\n");
	printf("                              ��ӭ����ʹ�ã��ټ�\n\n");
	//system("output.txt");

	return 0;
} 
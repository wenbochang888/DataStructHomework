#include "HeaderFile.h"


void ioFstream()
{
	//�ض������������
	//���Ӽ��������Ϊ���ļ��ж�ȡ
	//�������������̨��Ϊ������ļ�
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


	//���ļ��ж�ȡ���ʽ��ֱ�������ļ���ĩβ
    string expression;
    while(cin >> expression)
    {
        calOpr(expression);
    }

	//����������ļ���Ϊ���������̨
    freopen("CON","w",stdout);
}
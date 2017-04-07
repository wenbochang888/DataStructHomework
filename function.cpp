#include "HeaderFile.h"

//�ж��Ƿ�Ϊ������ +-*/^%
bool isOpr(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return true;          //��+-*/^%����true
    return false;             //���򷵻�false
}

//����isopr��ͬ���ж��Ƿ�Ϊ������ +-*/^%
bool isOpr(string ch)
{
    if(ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^" || ch == "%")
        return true;
    return false;
}

//�ж��Ƿ�Ϊ�����ţ�
bool isZuoKuoHao(char ch)
{
    if(ch == '(')
        return true;             //�������ŷ���true
    return false;                //���򷵻�false
}

//����isZuoKuoHao���ж��Ƿ�Ϊ�����ţ�
bool isZuoKuoHao(string ch)
{
    if(ch == "(")
        return true;
    return false;
}

//�ж��Ƿ�Ϊ�����ţ�
bool isYouKuoHao(char ch)
{
    if(ch == ')')
        return true;                //�������ŷ���true
    return false;                   //���򷵻�false
}

//����isYouKuoHao���ж��Ƿ�Ϊ�����ţ�
bool isYouKuoHao(string ch)
{
    if(ch == ")")
        return true;
    return false;
}

/*
*�ж�ջ�����ŵ����ȼ��ǲ��Ǹ��ڻ��ߵ��ڽ�ջ���ŵ����ȼ�
*�˷�^���ȼ���󣬳���*%���ȼ���Ȳ���С��^��+-�����ȼ���Ȳ�����С
*ֻҪջ�����Ÿ��ڻ��ߵ��ڽ�ջ���ŵ����ȼ�һ��Ҫ��ջ
*/
bool isHighOpr(string top, string in)
{
    if(top == "^")         //��Ϊ^������ȼ����ֻҪջ��Ϊ^��һ������true���ǳ�ջ
        return true;
    if(top == "*" && (in == "*" || in == "/" || in == "+" || in == "-" || in == "%"))
        return true;
    if(top == "/" && (in == "*" || in == "/" || in == "+" || in == "-" || in == "%"))
        return true;
    if(top == "%" && (in == "*" || in == "/" || in == "+" || in == "-" || in == "%"))
        return true;
    if(top == "+" && (in == "+" || in == "-"))
        return true;
    if(top == "-" && (in == "+" || in == "-"))
        return true;
    return false;
}

//���ַ���ת��Ϊdouble���͵�����
double strChangeToDouble(string a)
{
/*
*c++�е�һ����������string����ת��Ϊchar*����
*����ԭ��const char *c_str();
    */
    const char* ch = a.c_str();
    double n = atof(ch);
	
    return n;
}

string douChangeTostring(double a)
{
    string str = "";
    ostringstream oss;
    oss << a ;
    str = oss.str();
    return str;
}

/*
*�ж�n�ǲ������� �����ж�ȡ��%����ȷ��
*/
bool isZhengshu(double n)
{
    double t = n-int(n);
    if(t == 0)
        return true;
    return false;
}

/*��ʼ��strTemp����ַ�����
*��10+2.5 ��10��2.5����һ������.
*/
void init(string strTemp, string strMid[])
{
    int j = 0;                                 //j�൱����strmid��ָ��

    for(int i = 0; i<strTemp.length(); i++) //std::size_t
    {
   /*
   	* i!=0,�ų���һ��Ϊ������������-3+5
	*�ͻὫ-3����һ������string�ˡ�
    */
        if(isOpr(strTemp[i]) && i!=0)
        {
            if(strTemp[i] == '-')           //�ж��Ƿ��Ż��Ǽ���
            {
                if(strTemp[i-1] == '(')      //5+(-1) ���ű���������ţ�������Ϊ����
                    strMid[j] = strTemp[i];
                else                         //�������˻�����(1+2)����ʽ��
                {
                    j++;
                    strMid[j] = strTemp[i];
                    j++;
                }
            }
            else
            {
                j++;                         //����ǲ��������������ƶ�һλ���Ƶ���������
                strMid[j] = strTemp[i];      //����λ��������ֵ
                j++;                         //�����Ƶ�����λ
            }
            continue;
        }
        if(isZuoKuoHao(strTemp[i]))      //�����Ÿ�ֵ Ȼ��jָ���ƶ�
        {
            strMid[j] = strTemp[i];
            j++;
            continue;
        }
        if(isYouKuoHao(strTemp[i]))       //�����Ÿ�ֵ Ȼ��jָ���ƶ�
        {
            j++;
            strMid[j] = strTemp[i];
            continue;
        }
        /*
        *���������5�͸�ֵ��
        *�����12����1���ڽ�2������1��
        *�����2.5��ͬ�ϡ�����2��.��5
        *����-5 ͬ�� ����-��5
        */
        strMid[j]+=strTemp[i];
    }
}

void calOpr(string strTemp)
{
    string strMid[100];
    string strBack[100];
    init(strTemp, strMid);
    Stack s;
    InitStack(s);

    /*
    �����������һ����־����flag
    flag = 0��Ϊ��ȷ
    flag = 1����ʾ��0����
    flag = 2����ʾ�˷�����
    flag = 3����ʾȡ�����
    flag = 4; ��ʾ���ų��ִ���
    flag = 5; ��ʾ��ʾ���벻�Ϸ������� ����1++5
    */
	
	
    int flag = 0;
    int lenMid = 0;
    int lenBack = 0;
	
	int xx = 0;
	while(strMid[xx]!="")
	{
		 int cnt = 0;
		 for(int i = 0; i<strMid[xx].length(); i++)
		 {
			 if(strMid[xx][i] == '.')
				 cnt++;
		 }
		 if(cnt > 1)
		 {
			 cout << strTemp+"  ���������������С����̫����" << "\n\n";
			 return;
		 }
		 xx++;
	}

    while(strMid[lenMid]!="")
    {
        if(isOpr(strMid[lenMid]))
        {
            while(!isEmpty(s) && isHighOpr(getTop(s),strMid[lenMid]))
            {
                strBack[lenBack] = getTop(s);
                lenBack++;
                PopStack(s);
            }
            pushStack(s, strMid[lenMid]);
            lenMid++;
        }
        else if(isZuoKuoHao(strMid[lenMid]))
        {
            pushStack(s, strMid[lenMid]);
            lenMid++;
        }
        else if(isYouKuoHao(strMid[lenMid]))
        {
            while(!isEmpty(s) && !isZuoKuoHao(getTop(s)))
            {
                strBack[lenBack] = getTop(s);
                lenBack++;
                PopStack(s);
            }
            if(!isEmpty(s))
            {
                PopStack(s);
                lenMid++;
            }
            else
            {
                lenMid++;
                flag = 4;
            }
        }
        else
        {
            strBack[lenBack] = strMid[lenMid];
            lenMid++;
            lenBack++;
        }
    }
	
    while(!isEmpty(s))
    {
        strBack[lenBack] = getTop(s);
        lenBack++;
        PopStack(s);
    }
	
    InitStack(s);
	
    /*
    ����ת��׺���ʽ�Ѿ��ɹ�
    */
    int i = 0;
    while(strBack[i]!="")
    {
        if(isOpr(strBack[i]))
        {
            double a, b;
            if(strBack[i] == "+")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                a = strChangeToDouble(getTop(s));
                PopStack(s);
                pushStack(s, douChangeTostring(a+b));
                i++;
            }
            if(strBack[i] == "-")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                a = strChangeToDouble(getTop(s));
                PopStack(s);
                pushStack(s, douChangeTostring(a-b));
                i++;
            }
            if(strBack[i] == "*")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                a = strChangeToDouble(getTop(s));
                PopStack(s);
                pushStack(s, douChangeTostring(a*b));
                i++;
            }
            if(strBack[i] == "/")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                if(b == 0)
                {
                    flag = 1;
                    break;             //�������������ʶ��flagΪ1 ��ʾ��0����
                }
                else
                {
                    PopStack(s);
                    if(isEmpty(s))
                    {
                        flag = 5;
                        break;
                    }
                    a = strChangeToDouble(getTop(s));
                    PopStack(s);
                    pushStack(s, douChangeTostring(a/b));
                    i++;
                }
            }
            if(strBack[i] == "^")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                a = strChangeToDouble(getTop(s));
                PopStack(s);
                double res = pow(a, b);
                if(res)
                {
                    pushStack(s, douChangeTostring(res));
                    i++;
                }
                else
                {
                    flag = 2;
                    break;               //��������������flag��ʶ��Ϊ2����ʾ�˷�����
                }
            }
            if(strBack[i] == "%")
            {
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                b = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isEmpty(s))
                {
                    flag = 5;
                    break;
                }
                a = strChangeToDouble(getTop(s));
                PopStack(s);
                if(isZhengshu(a) && isZhengshu(b))
                {
                    int ai = int(a);
                    int bi = int(b);
                    pushStack(s, douChangeTostring(ai%bi));
                    i++;
                }
                else
                {
                    flag = 3;
                    break;              //��������������flag��ʶ��Ϊ3����ʾȡ�����
                }
            }
        }
        else if(strBack[i] == "(" || strBack[i] == ")")
        {
            flag = 4;
            break;
        }
        else
        {
            pushStack(s, strBack[i]);
            i++;
        }
    }
    if(flag == 0)
    {
		double res = strChangeToDouble(getTop(s));
		char buf[10];
		sprintf(buf, "%.2f", res);
		
        cout << strTemp + " = " + buf << "\n\n";
    }
    else
    {
        if(flag == 1)
            cout << strTemp+"  ������󣬳���Ϊ0" << "\n\n";
        if(flag == 2)
            cout << strTemp+"  ������󣬳˷�����Ϸ�����" << "\n\n";
        if(flag == 3)
            cout << strTemp+"  �������ȡ�����߱���Ϊ����" << "\n\n";
        if(flag == 4)
            cout << strTemp+"  ����������ű���ɶ�ƥ�����" << "\n\n";
        if(flag == 5)
            cout << strTemp+"  ����������������������߲�ƥ��" << "\n\n";
		
    }
}
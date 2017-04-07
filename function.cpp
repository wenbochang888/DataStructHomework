#include "HeaderFile.h"

//判断是否为操作符 +-*/^%
bool isOpr(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return true;          //是+-*/^%返回true
    return false;             //否则返回false
}

//重载isopr，同样判断是否为操作符 +-*/^%
bool isOpr(string ch)
{
    if(ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^" || ch == "%")
        return true;
    return false;
}

//判断是否为左括号（
bool isZuoKuoHao(char ch)
{
    if(ch == '(')
        return true;             //是左括号返回true
    return false;                //否则返回false
}

//重载isZuoKuoHao，判断是否为左括号（
bool isZuoKuoHao(string ch)
{
    if(ch == "(")
        return true;
    return false;
}

//判断是否为右括号）
bool isYouKuoHao(char ch)
{
    if(ch == ')')
        return true;                //是右括号返回true
    return false;                   //否则返回false
}

//重载isYouKuoHao，判断是否为左括号）
bool isYouKuoHao(string ch)
{
    if(ch == ")")
        return true;
    return false;
}

/*
*判断栈顶符号的优先级是不是高于或者等于进栈符号的优先级
*乘方^优先级最大，除法*%优先级相等并且小于^，+-的优先级相等并且最小
*只要栈顶符号高于或者等于进栈符号的优先级一定要出栈
*/
bool isHighOpr(string top, string in)
{
    if(top == "^")         //因为^这个优先级最大，只要栈顶为^，一定返回true就是出栈
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

//将字符串转化为double类型的数字
double strChangeToDouble(string a)
{
/*
*c++中的一个函数，将string类型转化为char*类型
*函数原型const char *c_str();
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
*判断n是不是整数 用于判断取余%的正确性
*/
bool isZhengshu(double n)
{
    double t = n-int(n);
    if(t == 0)
        return true;
    return false;
}

/*初始化strTemp这个字符串。
*如10+2.5 将10和2.5看成一个整体.
*/
void init(string strTemp, string strMid[])
{
    int j = 0;                                 //j相当于是strmid的指针

    for(int i = 0; i<strTemp.length(); i++) //std::size_t
    {
   /*
   	* i!=0,排除第一个为负数。即比如-3+5
	*就会将-3看成一个整体string了。
    */
        if(isOpr(strTemp[i]) && i!=0)
        {
            if(strTemp[i] == '-')           //判断是符号还是减号
            {
                if(strTemp[i-1] == '(')      //5+(-1) 符号必须加上括号，否则视为错误
                    strMid[j] = strTemp[i];
                else                         //存在有人会输入(1+2)这种式子
                {
                    j++;
                    strMid[j] = strTemp[i];
                    j++;
                }
            }
            else
            {
                j++;                         //如果是操作符，就往后移动一位，移到操作符上
                strMid[j] = strTemp[i];      //将该位操作符赋值
                j++;                         //往后移到数字位
            }
            continue;
        }
        if(isZuoKuoHao(strTemp[i]))      //左括号赋值 然后j指针移动
        {
            strMid[j] = strTemp[i];
            j++;
            continue;
        }
        if(isYouKuoHao(strTemp[i]))       //左括号赋值 然后j指针移动
        {
            j++;
            strMid[j] = strTemp[i];
            continue;
        }
        /*
        *如果是数字5就赋值。
        *如果是12就先1，在将2连接上1上
        *如果是2.5，同上。连接2和.和5
        *负数-5 同理 连接-和5
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
    运算出错设置一个标志符号flag
    flag = 0；为正确
    flag = 1；表示除0出错
    flag = 2；表示乘方出错
    flag = 3；表示取余出错
    flag = 4; 表示括号出现错误
    flag = 5; 表示表示输入不合法的运算 比如1++5
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
			 cout << strTemp+"  输入错误，输入数字小数点太多啦" << "\n\n";
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
    这里转后缀表达式已经成功
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
                    break;             //运算结果出错，设标识符flag为1 表示除0错误
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
                    break;               //运算结果出错，设置flag标识符为2，表示乘方出错
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
                    break;              //运算结果出错，设置flag标识符为3，表示取余出错
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
            cout << strTemp+"  输入错误，除数为0" << "\n\n";
        if(flag == 2)
            cout << strTemp+"  输入错误，乘方必须合法规则" << "\n\n";
        if(flag == 3)
            cout << strTemp+"  输入错误，取余两边必须为整数" << "\n\n";
        if(flag == 4)
            cout << strTemp+"  输入错误，括号必须成对匹配出现" << "\n\n";
        if(flag == 5)
            cout << strTemp+"  输入错误，输入操作符过多或者不匹配" << "\n\n";
		
    }
}
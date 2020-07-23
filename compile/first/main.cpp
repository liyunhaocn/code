#include<iostream>
using namespace std;
int main()
{
    void fun(char*a);
    char a[100]={};//保存用户输入，
    //接收输入，不要超过100个字符，否则getline会设置失效位，
    //（如果有的话）接下来的输入将被阻断,需要的话，可以调用cin.clear()恢复输入
    cin.getline(a,100);//遇见回车表示输入结束
    fun(a);
    cout<<endl<<endl<<endl;
    return 0;
}
void fun(char* a)//功能函数
{
    int mov(int im,char c);
    void output(int i,string s);
    string s=a;//将用户输入转换为string类型，因为string.substr比较好用，接下来就会看到
    string keyWord[]={"for","if","then","else","while","do","until","int","input","output"};//关键字
    int kwLenth=sizeof(keyWord)/sizeof(string);//keyWord数组的元素个数
    int tokenKw[]={1,2,3,4,5,6,29,30,31,32};//关键字对应的记号
    int last=0;//待操作终止位，包括这一位
    int start=0;//待操作起始位
    int im=0;//move函数的输入，input_of_move的缩写
    int om=1;//move函数的输出，output_of_move的缩写
    string sub="";//保存当前有效字串
    for(last=0;last<s.size();++last)//扫描输入的源程序
    {
        if(int(s[last])==32||int(s[last])==9)//遇见空格或者水平制表符
        {//（程序中一般不会用水平制表符作为分隔符，为程序完整起见，这里加上了对水平制表符的判断）
            start++;
            //im=0;
            continue;
        }
        sub=s.substr(start,last+1-start);//第一个参数是起始位置，第二个参数是偏移量
        om=mov(im,s[last]);//调用mov函数
        int kw=0;
        switch(om)
        {
        case 1://应该用im对应的终态，即上一个终态
            sub=s.substr(start,last-start);//第一个参数是起始位置，第二个参数是偏移量
            output(im,sub);//输出记号流
            start=last;//移动待操作起始位
            last--;//使得下一轮循环重新读取当前字符
            im=0;//对im置0，因为将要寻找下一个词法单元
            break;
        case 5://单个运算符或分隔符对应的终态
            output(5,sub);
            start=last+1;
            im=0;
            break;
        case 7://<>对应的终态
            output(7,sub);
            start=last+1;
            im=0;
            break;
        case 8://<=对应的终态
            output(8,sub);
            start=last+1;
            im=0;
            break;
        case 9://>=对应的终态
            output(9,sub);
            start=last+1;
            im=0;
            break;
        case 10://:=对应的终态
            output(10,sub);
            start=last+1;
            im=0;
            break;
        case 12://可能是关键字
            for(kw=0;kw<kwLenth;++kw)
            {
                if(sub==keyWord[kw])
                    break;
            }
            if(kw<kwLenth)//匹配关键字成功
            {
                cout<<" ("<<tokenKw[kw]<<","<<sub<<")";
                start=last+1;
                im=0;
            }
            else
                im=om;//不确定终态，还未找到词法单元
            break;
        default://其它值不能确定是终态,除非当前是最后一个字符
            if(last==s.size()-1)
            {
                output(om,sub);
            }
            else
                im=om;//不确定终态，还未找到词法单元
        }
    }
}
int mov(int im,char c)//move函数，需要结合状态转换图理解
{
    int asc=(int)c;//获取当前字符的ASCLL码
    int om=0;//保存mov函数的输出，将作为返回值
    switch(im)
    {
    case 0://从0开始
        if(asc>=48&&asc<=57)//遇见数字
            om=6;
        else if(asc>=65&&asc<=90||asc>=97&&asc<=122)//遇见字母
            om=11;
        else//遇见运算符或分隔符
        {
            if(c=='<')
                om=2;
            else if(c=='>')
                om=3;
            else if(c==':')
                om=4;
            else//遇见其它运算符或分隔符
                om=5;
        }
        break;
    case 2:
        if(c=='>')//表示<>
            om=7;
        else if(c=='=')//表示<=
            om=8;
        else
            om=1;//表示im
        break;
    case 3:
        if(c=='=')//表示>=
            om=9;
        else
            om=1;
        break;
    case 4:
        if(c=='=')//表示:=
            om=10;
        else
            om=1;
        break;
    case 6:
        if(asc>=48&&asc<=57)//遇见数字
            om=6;
        else
            om=1;
        break;
    case 11:
        if(asc>=65&&asc<=90||asc>=97&&asc<=122)//遇见字母
            om=12;
        else if(asc>=48&&asc<=57)//遇见数字
            om=13;
        else
            om=1;
        break;
    case 12:
        if(asc>=65&&asc<=90||asc>=97&&asc<=122)//遇见字母
            om=12;
        else if(asc>=48&&asc<=57)//遇见数字
            om=13;
        else
            om=1;
        break;
    case 13:
        if(asc>=48&&asc<=57)//遇见数字
            om=13;
        else
            om=1;
    default:
        ;
    }
    return om;
}
void output(int i,string s)//输入一个数字和当前有效子串，输出其对应的词法单元的记号流
{
    int trans(char c);
    switch(i)
    {
    case 2://表示<,是单个字符
        ;
    case 3://表示>，是单个字符
        ;
    case 4://表示:，是单个字符
        ;
    case 5://表示单个的运算符或分隔符
        cout<<" ("<<trans(s[0])<<","<<s<<")";
        break;
    case 6://表示数字
        cout<<" (11,"<<s<<")";
        break;
    case 7://表示<>
        cout<<" (21,<>)";
        break;
    case 8://表示<=
        cout<<" (22,<)";
        break;
    case 9://表示>=
        cout<<" (24,<)";
        break;
    case 10://表示:=
        cout<<" (18,:=)";
        break;
    case 11://表示id
       ;
    case 12://表示id
        ;
    case 13://表示id
        cout<<" (10,"<<s<<")";
        break;
    default:
        ;
    }
}
int trans(char c)//输入一个单运算符或分隔符，返回对应的词法记号，需要结合表格理解
{
    int token=0;
    switch(c)
    {
    case ':':
        token=17;
        break;
    case '=':
        token=25;
        break;
    case '+':
        token=13;
        break;
    case '-':
        token=14;
        break;
    case '*':
        token=15;
        break;
    case '/':
        token=16;
        break;
    case '<':
        token=20;
        break;
    case '>':
        token=23;
        break;
    case ';':
        token=26;
        break;
    case '(':
        token=27;
        break;
    case ')':
        token=28;
        break;
    case '#':
        token=0;
        break;
    default:
        ;
    }
    return token;
}

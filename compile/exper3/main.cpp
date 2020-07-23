#include<iostream>

using namespace std;

static string ahead="";//当前正待处理的输入记号
static string sub="";//当前待处理记号被处理后的输入
void E();
void E_();//表示E'
void T();
void T_();//表示T'
void F();
void error();
void match(string t);
string nextToken();
int main()
{
    //不用自己输入#
    char a[100]={};//保存用户输入，接收输入，不要超过100个字符，否则getline会设置失效位，接下来的输入(如果有的话)将被阻断,需要的话，可以调用cin.clear()恢复输入
    cin.getline(a,100);//遇见回车表示输入结束
    sub=a;
    sub+='#';
    ahead=nextToken();
    E();//因为E是开始符号
    return 0;
}
void E()
{
    if(ahead=="("||ahead=="id")//First(T)={(,id}
    {
        cout<<"E→TE'"<<endl;
        T();
        E_();
    }
    else if(ahead==")"||ahead=="#")//Follow(E)加入到E的同步记号集合中
    {
        error();
       //出错，但无须跳过任何记号，跳过E即可，即不作任何处理
        ;
    }
    else//出错，当前记号不在E的同步记号集合中，跳过当前记号
    {
        error();
        ahead=nextToken();
        E();
    }
}
void E_()
{
    if(ahead=="+")
    {
        cout<<"E'→+TE'"<<endl;
        match("+");
        T();
        E_();
    }
    else if(ahead==")"||ahead=="#")//Follow(E')={),$},这里#代表$
    {
        cout<<"E'→ε"<<endl;
    }
    else//出错，当前记号不在E'的同步记号集合中，跳过当前记号
    {
        error();
        ahead=nextToken();
        E_();
    }
}
void T()
{
    if(ahead=="("||ahead=="id")//First(F)={(,id}
    {
       cout<<"T→FT'"<<endl;
       F();
       T_();
    }
    else if(ahead=="+"||ahead==")"||ahead=="#")//Follow(T)加入到T的同步记号集合中
    {
         error();
       //出错，但无须跳过任何记号，跳过T即可，即不作任何处理
        ;
    }
    else//出错，当前记号不在T的同步记号集合中，跳过当前记号
    {
        error();
        ahead=nextToken();
        T();
    }
}
void T_()
{
    if(ahead=="*")
    {
        cout<<"T'→*FT'"<<endl;
        match("*");
        F();
        T_();
    }
    else if(ahead=="+"||ahead==")"||ahead=="#")//FOllow(T')={+,),$},这里#代表$
    {
        cout<<"T'→ε"<<endl;
    }
    else//出错，当前记号不在T'的同步记号集合中，跳过当前记号
    {
        error();
        ahead=nextToken();
        T_();
    }
}
void F()
{
    if(ahead=="(")
    {
        cout<<"F→（E）"<<endl;;
        match("(");
        E();
        match(")");
    }
    else if(ahead=="id")
    {
        cout<<"F→id"<<endl;;
         match("id");
    }
    else if(ahead=="+"||ahead=="*"||ahead==")"||ahead=="#")//Follow(F)加入到F的同步记号集合中
    {
          error();
       //出错，但无须跳过任何记号，跳过 F 即可，即不作任何处理
        ;
    }
    else//出错，当前记号不在 F 的同步记号集合中，跳过当前记号
    {
        error();
        ahead=nextToken();
        F();
    }
}
void error()
{
    cout<<"匹配失败！！！"<<endl;
}
void match(string t)
{
    if(ahead==t)
    {
        cout<<"匹配"<<ahead<<endl;
        ahead=nextToken();
    }
    else
        error();
}
string nextToken()//获取下一个词法记号
{
    if(sub.substr(0,2)=="id")
    {
         sub=sub.substr(2,sub.size()-2);
         return "id";
    }
    else
    {
        string s=sub.substr(0,1);
        sub=sub.substr(1,sub.size()-1);
        return s;
    }
}

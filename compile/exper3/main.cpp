#include<iostream>

using namespace std;

static string ahead="";//��ǰ�������������Ǻ�
static string sub="";//��ǰ������Ǻű�����������
void E();
void E_();//��ʾE'
void T();
void T_();//��ʾT'
void F();
void error();
void match(string t);
string nextToken();
int main()
{
    //�����Լ�����#
    char a[100]={};//�����û����룬�������룬��Ҫ����100���ַ�������getline������ʧЧλ��������������(����еĻ�)�������,��Ҫ�Ļ������Ե���cin.clear()�ָ�����
    cin.getline(a,100);//�����س���ʾ�������
    sub=a;
    sub+='#';
    ahead=nextToken();
    E();//��ΪE�ǿ�ʼ����
    return 0;
}
void E()
{
    if(ahead=="("||ahead=="id")//First(T)={(,id}
    {
        cout<<"E��TE'"<<endl;
        T();
        E_();
    }
    else if(ahead==")"||ahead=="#")//Follow(E)���뵽E��ͬ���Ǻż�����
    {
        error();
       //���������������κμǺţ�����E���ɣ��������κδ���
        ;
    }
    else//������ǰ�ǺŲ���E��ͬ���Ǻż����У�������ǰ�Ǻ�
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
        cout<<"E'��+TE'"<<endl;
        match("+");
        T();
        E_();
    }
    else if(ahead==")"||ahead=="#")//Follow(E')={),$},����#����$
    {
        cout<<"E'����"<<endl;
    }
    else//������ǰ�ǺŲ���E'��ͬ���Ǻż����У�������ǰ�Ǻ�
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
       cout<<"T��FT'"<<endl;
       F();
       T_();
    }
    else if(ahead=="+"||ahead==")"||ahead=="#")//Follow(T)���뵽T��ͬ���Ǻż�����
    {
         error();
       //���������������κμǺţ�����T���ɣ��������κδ���
        ;
    }
    else//������ǰ�ǺŲ���T��ͬ���Ǻż����У�������ǰ�Ǻ�
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
        cout<<"T'��*FT'"<<endl;
        match("*");
        F();
        T_();
    }
    else if(ahead=="+"||ahead==")"||ahead=="#")//FOllow(T')={+,),$},����#����$
    {
        cout<<"T'����"<<endl;
    }
    else//������ǰ�ǺŲ���T'��ͬ���Ǻż����У�������ǰ�Ǻ�
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
        cout<<"F����E��"<<endl;;
        match("(");
        E();
        match(")");
    }
    else if(ahead=="id")
    {
        cout<<"F��id"<<endl;;
         match("id");
    }
    else if(ahead=="+"||ahead=="*"||ahead==")"||ahead=="#")//Follow(F)���뵽F��ͬ���Ǻż�����
    {
          error();
       //���������������κμǺţ����� F ���ɣ��������κδ���
        ;
    }
    else//������ǰ�ǺŲ��� F ��ͬ���Ǻż����У�������ǰ�Ǻ�
    {
        error();
        ahead=nextToken();
        F();
    }
}
void error()
{
    cout<<"ƥ��ʧ�ܣ�����"<<endl;
}
void match(string t)
{
    if(ahead==t)
    {
        cout<<"ƥ��"<<ahead<<endl;
        ahead=nextToken();
    }
    else
        error();
}
string nextToken()//��ȡ��һ���ʷ��Ǻ�
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

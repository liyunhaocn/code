#include<iostream>
using namespace std;
int main()
{
    void fun(char*a);
    char a[100]={};//�����û����룬
    //�������룬��Ҫ����100���ַ�������getline������ʧЧλ��
    //������еĻ��������������뽫�����,��Ҫ�Ļ������Ե���cin.clear()�ָ�����
    cin.getline(a,100);//�����س���ʾ�������
    fun(a);
    cout<<endl<<endl<<endl;
    return 0;
}
void fun(char* a)//���ܺ���
{
    int mov(int im,char c);
    void output(int i,string s);
    string s=a;//���û�����ת��Ϊstring���ͣ���Ϊstring.substr�ȽϺ��ã��������ͻῴ��
    string keyWord[]={"for","if","then","else","while","do","until","int","input","output"};//�ؼ���
    int kwLenth=sizeof(keyWord)/sizeof(string);//keyWord�����Ԫ�ظ���
    int tokenKw[]={1,2,3,4,5,6,29,30,31,32};//�ؼ��ֶ�Ӧ�ļǺ�
    int last=0;//��������ֹλ��������һλ
    int start=0;//��������ʼλ
    int im=0;//move���������룬input_of_move����д
    int om=1;//move�����������output_of_move����д
    string sub="";//���浱ǰ��Ч�ִ�
    for(last=0;last<s.size();++last)//ɨ�������Դ����
    {
        if(int(s[last])==32||int(s[last])==9)//�����ո����ˮƽ�Ʊ��
        {//��������һ�㲻����ˮƽ�Ʊ����Ϊ�ָ�����Ϊ���������������������˶�ˮƽ�Ʊ�����жϣ�
            start++;
            //im=0;
            continue;
        }
        sub=s.substr(start,last+1-start);//��һ����������ʼλ�ã��ڶ���������ƫ����
        om=mov(im,s[last]);//����mov����
        int kw=0;
        switch(om)
        {
        case 1://Ӧ����im��Ӧ����̬������һ����̬
            sub=s.substr(start,last-start);//��һ����������ʼλ�ã��ڶ���������ƫ����
            output(im,sub);//����Ǻ���
            start=last;//�ƶ���������ʼλ
            last--;//ʹ����һ��ѭ�����¶�ȡ��ǰ�ַ�
            im=0;//��im��0����Ϊ��ҪѰ����һ���ʷ���Ԫ
            break;
        case 5://�����������ָ�����Ӧ����̬
            output(5,sub);
            start=last+1;
            im=0;
            break;
        case 7://<>��Ӧ����̬
            output(7,sub);
            start=last+1;
            im=0;
            break;
        case 8://<=��Ӧ����̬
            output(8,sub);
            start=last+1;
            im=0;
            break;
        case 9://>=��Ӧ����̬
            output(9,sub);
            start=last+1;
            im=0;
            break;
        case 10://:=��Ӧ����̬
            output(10,sub);
            start=last+1;
            im=0;
            break;
        case 12://�����ǹؼ���
            for(kw=0;kw<kwLenth;++kw)
            {
                if(sub==keyWord[kw])
                    break;
            }
            if(kw<kwLenth)//ƥ��ؼ��ֳɹ�
            {
                cout<<" ("<<tokenKw[kw]<<","<<sub<<")";
                start=last+1;
                im=0;
            }
            else
                im=om;//��ȷ����̬����δ�ҵ��ʷ���Ԫ
            break;
        default://����ֵ����ȷ������̬,���ǵ�ǰ�����һ���ַ�
            if(last==s.size()-1)
            {
                output(om,sub);
            }
            else
                im=om;//��ȷ����̬����δ�ҵ��ʷ���Ԫ
        }
    }
}
int mov(int im,char c)//move��������Ҫ���״̬ת��ͼ���
{
    int asc=(int)c;//��ȡ��ǰ�ַ���ASCLL��
    int om=0;//����mov���������������Ϊ����ֵ
    switch(im)
    {
    case 0://��0��ʼ
        if(asc>=48&&asc<=57)//��������
            om=6;
        else if(asc>=65&&asc<=90||asc>=97&&asc<=122)//������ĸ
            om=11;
        else//�����������ָ���
        {
            if(c=='<')
                om=2;
            else if(c=='>')
                om=3;
            else if(c==':')
                om=4;
            else//���������������ָ���
                om=5;
        }
        break;
    case 2:
        if(c=='>')//��ʾ<>
            om=7;
        else if(c=='=')//��ʾ<=
            om=8;
        else
            om=1;//��ʾim
        break;
    case 3:
        if(c=='=')//��ʾ>=
            om=9;
        else
            om=1;
        break;
    case 4:
        if(c=='=')//��ʾ:=
            om=10;
        else
            om=1;
        break;
    case 6:
        if(asc>=48&&asc<=57)//��������
            om=6;
        else
            om=1;
        break;
    case 11:
        if(asc>=65&&asc<=90||asc>=97&&asc<=122)//������ĸ
            om=12;
        else if(asc>=48&&asc<=57)//��������
            om=13;
        else
            om=1;
        break;
    case 12:
        if(asc>=65&&asc<=90||asc>=97&&asc<=122)//������ĸ
            om=12;
        else if(asc>=48&&asc<=57)//��������
            om=13;
        else
            om=1;
        break;
    case 13:
        if(asc>=48&&asc<=57)//��������
            om=13;
        else
            om=1;
    default:
        ;
    }
    return om;
}
void output(int i,string s)//����һ�����ֺ͵�ǰ��Ч�Ӵ���������Ӧ�Ĵʷ���Ԫ�ļǺ���
{
    int trans(char c);
    switch(i)
    {
    case 2://��ʾ<,�ǵ����ַ�
        ;
    case 3://��ʾ>���ǵ����ַ�
        ;
    case 4://��ʾ:���ǵ����ַ�
        ;
    case 5://��ʾ�������������ָ���
        cout<<" ("<<trans(s[0])<<","<<s<<")";
        break;
    case 6://��ʾ����
        cout<<" (11,"<<s<<")";
        break;
    case 7://��ʾ<>
        cout<<" (21,<>)";
        break;
    case 8://��ʾ<=
        cout<<" (22,<)";
        break;
    case 9://��ʾ>=
        cout<<" (24,<)";
        break;
    case 10://��ʾ:=
        cout<<" (18,:=)";
        break;
    case 11://��ʾid
       ;
    case 12://��ʾid
        ;
    case 13://��ʾid
        cout<<" (10,"<<s<<")";
        break;
    default:
        ;
    }
}
int trans(char c)//����һ�����������ָ��������ض�Ӧ�Ĵʷ��Ǻţ���Ҫ��ϱ�����
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

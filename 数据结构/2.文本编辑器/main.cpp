#include<iostream>
#include<list>
#include<string.h>
#include<stdio.h>
using namespace std;

class TextEditor{
private:
    int cursor;
    int line;
    int offset;    //ƫ��
    int total;     //����������
    string name;
    list<string> article;

    int letters;   //��ĸ��
    int quots;
    int nums;      //������
    int spaces;     //�ո���
public:
    TextEditor() {
        name="Untitled";
        line=1;    //������
        offset=1;  //�������ƫ����
        total=0;
        cursor=1;    //�����������
        nums=0;
        letters=0;
        quots=0;
    }

    ~TextEditor()  {};

    list<string>::iterator getIndex(int x){
        if(x<0)
            x=0;
        if(x>line)
            x=line;
        list<string>::iterator it;
        int l = 0;
        for(it=article.begin();it!=article.end();it++){
            l++;
            if(l==x) break;
        }
        return  it;    //���ص���������
    }

    const string & getName() const{
        return name;
    }

    void setName(const string &name){
        if(name.length()!=0){
            this->name=name;
        }
    }

    void  getCursor(int * pLine=NULL,int *pOffset=NULL) {
        *pLine=cursor;
        *pOffset=offset;
    }

    void MoveCursor(int offset){
        list<string>::iterator it=getIndex(cursor);
        this->offset+=offset;
        while(it->length()<this->offset&&it!=article.end()) {
            this->offset-=it->length();
            cursor++;
            it++;
        }
    }

    void setCursor(int line ,int offset){
        if(line>article.size())    //������ù��������������µ�������
            line = (int)article.size();
        this->cursor=line;     //������������һ��
        if(offset<0) offset=0;
        if(offset>getIndex(line)->length()) offset= (int)getIndex(line)->length();
        this->offset=offset;
    }

    void addText(const string & text){
        article.push_back(text);
        total+=text.length();
        for(int i=0;i<text.length();i++){
            if(text[i]==' ')
                spaces++;
            else if(text[i]>='0'&&text[i]<='9')
                nums++;
            else if(text[i]>='a'&&text[i]<='z')
                letters++;
            else if(text[i]>='A'&&text[i]<='Z')
                letters++;
            else
                quots++;
        }
        line++;
    }

    int insertText(string text){
        total+=text.length();
        for(int i=0;i<text.length();i++){
            if(text[i]==' ')
                spaces++;
            else if(text[i]>='0'&&text[i]<='9')
                nums++;
            else if(text[i]>='a'&&text[i]<='z')
                letters++;
            else if(text[i]>='A'&&text[i]<='Z')
                letters++;
            else
                quots++;
        }

        if(article.empty()) {
            article.push_back(text);
            offset = (int)text.length();
            return 1;
        }

        list<string>::iterator it = getIndex(cursor);

        string temp=it->substr(0,offset);
        temp+=text;
        temp +=it->substr(offset);
        *it = temp;
        return 1;
    }

    int findText(const string & text ,int *line,int *offset){
        list<string>::iterator it;
        int l=0;
        int li = *line;
        int pp = *offset;
        for(it=article.begin();it!=article.end();it++){
            l++;
            if(*line>l)
                continue;
            if(*line<l)
                *offset = -1;
            if(it->find(text,(*offset)+1)!=string::npos){
                *line = l;
                *offset = (int)it->find(text,(*offset)+1);
                return 1;
            }
        }

        if(li==*line&&pp==*offset)
            *offset=-1;
        return 1;
    }

    void deleteText(const string & text){
        int line=1,offset=-1;
        findText(text,&line,&offset);
        while(1){
            if(offset==-1)
                break;
            cout<<"�Ƿ�ɾ����"<<line<<"��λ��"<<offset<<"��������(Y or N):";
            char c;
            cin>>c;
            if(c!='Y'&&c!='y') continue;
            deleteText(line,offset,(int)text.length());
            findText(text,&line,&offset);
        }
    }

    int min(int x,int y){
        return x<y?x:y;
    }

    void deleteText(int cursor ,int pos,int length){
        list<string>::iterator it = getIndex(cursor);
        total-=length;
        string text = *it;
        for(int i=pos;i<min((int)it->length(),pos+length);i++){
            if(text[i]==' ')
                spaces--;
            else if(text[i]>='0'&&text[i]<='9')
                nums--;
            else if(text[i]>='a'&&text[i]<='z')
                letters--;
            else if(text[i]>='A'&&text[i]<='Z')
                letters--;
            else
                quots--;
        }
        *it = it->erase(pos,length);  //ɾ���������е�����
    }

    void wordState() {
        cout<<"������"<<total<<endl;
        cout<<"�ո���"<<spaces<<endl;
        cout<<"������"<<nums<<endl;
        cout<<"��ĸ��"<<letters<<endl;
        cout<<"������"<<quots<<endl;
    }

    friend ostream & operator<<(ostream & out,TextEditor & editor){
        int line = 1;
        list<string>::iterator it;
        out<<editor.name<<".txt"<<endl;
        for (it = editor.article.begin();it!=editor.article.end();it++){
            line++;
            out<<*it<<endl;
        }
        out<<endl;
        return out;
    }
};


int main(){
    TextEditor text;
    int k=3;
    char s[100];
    cout<<"�������ļ���"<<endl;
    gets(s);
    text.setName(s);
    while(k--){
    gets(s);
    text.addText(s);
    }
    cout<<text;
    int m,n;
    text.getCursor(&m,&n);
    cout<<"��"<<m<<"�У���"<<n<<"��"<<endl;
    int x,y;
    cout<<"������Ҫ�����λ��"<<endl;
    cin>>x>>y;
    text.setCursor(x,y);
    text.MoveCursor(0);
    string ins;
    cout<<"������Ҫ������ַ�"<<endl;
    cin>>ins;
    text.insertText(ins);
    cout<<text;
    n=1;
    m=1;
    cout<<"������Ҫɾ�����ַ�"<<endl;
    string del;
    cin>>del;
    text.findText(del,&m,&n);
    cout<<"��"<<m<<"�У���"<<n<<"��"<<endl;
    text.deleteText(del);
    cout<<text;
    //text.wordState();
    return 0;
}

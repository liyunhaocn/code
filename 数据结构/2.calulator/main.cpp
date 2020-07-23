#include <iostream>
#include <stack>
using namespace std;

class Calculator{
private:
    int Priority(char fuhao);
    double CalSuffix(string PostfixExp);
    string InfixToSuffix(string InfixExp);
public:
    double Calculate(string InfixExp);

};

double Calculator::CalSuffix(string PostfixExp){
    double tmpresult,ch1,ch2;
    double tmpnum,tmpxiaoshu=1;
    int i=0,tmpdashu;
    int isfu=0;  ///
    stack<double> stk2;
    while(PostfixExp[i]!='\0'){
        isfu=0;  ///
        if(PostfixExp[i]>=48&&PostfixExp[i]<=57){
            if(PostfixExp[i-1]=='-'){     /////
                isfu=1;
                cout<<"是负数";
            }
            tmpxiaoshu=1;
            tmpdashu=10;
            tmpnum = PostfixExp[i]-48;
            while(PostfixExp[++i]>=48&&PostfixExp[i]<=57){
                tmpnum = tmpnum*tmpdashu+ (PostfixExp[i]-48);
            }
            i=i-1;
            if(PostfixExp[++i]=='.'){
                while(PostfixExp[++i]>=48&&PostfixExp[i]<=57){
                    tmpxiaoshu=tmpxiaoshu*0.1;
                    tmpnum = tmpnum + (PostfixExp[i]-48)*tmpxiaoshu;
                }
                i=i-1;
            }
            else{
                i=i-1;
            }
            if(isfu){
                tmpnum=tmpnum*(-1);
            }
            stk2.push(tmpnum);
        }

        else if(PostfixExp[i]=='&'||PostfixExp[i]==' '){
        }

        else {
            if(PostfixExp[++i]>=48&&PostfixExp[i]<=57){
                i=i-1;
            }
            else {
                i=i-1;
                ch2 = stk2.top();
                stk2.pop();
                ch1 = stk2.top();
                stk2.pop();
                switch(PostfixExp[i]){
                    case '+': tmpnum = ch1 + ch2; break;
                    case '-': tmpnum = ch1 - ch2;  break;
                    case '*': tmpnum = ch1 * ch2; break;
                    case '/': tmpnum = ch1 / ch2;  break;
                }
                stk2.push(tmpnum);
            }
        }
        i++;
    }
    if(stk2.empty()!=1){
      tmpresult = stk2.top();
      stk2.pop();
    }
    return tmpresult;
}

double Calculator::Calculate(string InfixExp){
    double result;
    result = CalSuffix(InfixToSuffix(InfixExp));
    return result;
}

int Calculator::Priority(char fuhao){
    switch(fuhao){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        case '(':
        case ')': return 1;
        default:
            return 0;
    }
}
string Calculator::InfixToSuffix(string InfixExp){
    stack<char> stk;
    string PostfixExp = "                  ";
    int i=0,j=0;
    char tmpfuhao;
    int flag = 0;  //判断多位数的头数是否为零
    while(InfixExp[i]!='\0'){
        if(InfixExp[i]>=48&&InfixExp[i]<=57){
            flag = 0;
            PostfixExp[j++]='&';
            PostfixExp[j++]=InfixExp[i];
            if(InfixExp[i]=='0'){
                flag = 1;
            }
            while(InfixExp[++i]>=48&&InfixExp[i]<=57){
                if(flag==0)
                    PostfixExp[j++]=InfixExp[i];
                else
                    cout<<"输入错误数字";
            }
            i=i-1;
            if(InfixExp[++i]=='.'){
                PostfixExp[j++]='.';
                while(InfixExp[++i]>=48&&InfixExp[i]<=57){
                    PostfixExp[j++]=InfixExp[i];
                }
                i=i-1;
            }
            else{
                i=i-1;
            }
        }

        else if(InfixExp[i]=='('){
            stk.push(InfixExp[i]);
        }

        else if(InfixExp[i]==')'){
            if(stk.empty()){
               cout<<"表达式错误！";
            }
            else{
               tmpfuhao = stk.top();
               while(tmpfuhao!='('){
                   if(stk.empty()){
                       cout<<"表达式错误!";
                   }
                   else{
                       PostfixExp[j++] = '&';
                       PostfixExp[j++] = tmpfuhao;
                       stk.pop();
                       tmpfuhao = stk.top();
                   }
                }
                stk.pop();
            }
        }

        else if(InfixExp[i]=='+'||InfixExp[i]=='-'||InfixExp[i]=='*'||InfixExp[i]=='/'){
            if(i==0||((InfixExp[--i]<48||InfixExp[i]>57)&&InfixExp[i]!=')')){
                i++;
                PostfixExp[j++]='&';
                PostfixExp[j++]='-';
                while(InfixExp[++i]>=48&&InfixExp[i]<=57){
                    PostfixExp[j++]=InfixExp[i];
                }
                i=i-1;
                if(InfixExp[++i]=='.'){
                    PostfixExp[j++]='.';
                    while(InfixExp[++i]>=48&&InfixExp[i]<=57){
                        PostfixExp[j++]=InfixExp[i];
                    }
                    i=i-1;
                }
                else{
                    i=i-1;
                }
            }
            else{
                i++;
            if(stk.empty()){
                stk.push(InfixExp[i]);
            }
            else{
                tmpfuhao = stk.top();
                if(Priority(tmpfuhao)<Priority(InfixExp[i])){
                    stk.push(InfixExp[i]);
                }
                else{
                    while(Priority(tmpfuhao)>=Priority(InfixExp[i])){
                        PostfixExp[j++] = '&';
                        PostfixExp[j++] = tmpfuhao;
                        stk.pop();
                        if(stk.empty()!=1){
                           tmpfuhao = stk.top();
                        }
                        else break;
                    }
                    stk.push(InfixExp[i]);
                }
            }
            }
        }
        else{
            cout<<"符号错误！";
            break;
        }
        i++;
    }

    while(!stk.empty()){
        tmpfuhao = stk.top();
        PostfixExp[j++] = '&';
        PostfixExp[j++] = tmpfuhao;
        stk.pop();
    }
    PostfixExp[j++] = '\0';
    return PostfixExp;
}

int main() {
    string zhong;
    Calculator a;
    cout<<"输入中缀表达式"<<endl;
    cin>>zhong;
    cout<<"计算结果为"<<endl;
    cout<<a.Calculate(zhong)<<endl;
    return 0;
}




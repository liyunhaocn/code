#include <iostream>
#include <string>
#include <typeinfo>
#include <stack>
#include <vector>
#include<sstream>
using namespace std;

int str_int(string s){
    stringstream ss;
    int a;
    ss<<s;
    ss>>a;
    return a;
}

bool is_dig(string a){
    if(a.size()==1 && a>="0" && a <= "9"){
        return true;
    }else{
        return false;
    }
}
bool is_c(string a){
    if(a.size()==1 && (a=="+" || a == "-"|| a == "*"|| a == "/"|| a == "("|| a == ")")){
        return true;
    }else{
        return false;
    }
}

vector<string> str_ve(string s){
    vector<string> ve;
    int i = 0;
    while(i<s.size()){
        if(!is_dig(s.substr(i,1))){
            ve.push_back(s.substr(i,1));
            i++;
        }else{
            int j = i;
            while(is_dig(s.substr(j,1))){
                j++;
            }
            ve.push_back(s.substr(i,j-i));
            i=j;
        }
    }
    return ve;

}
int get_pri(string s){
    if(s.size()!=1){
        return -1;
    }
    if(s=="("){
        return 1;
    }else if(s=="+" || s=="-"){
        return 2;
    }else if(s=="*" || s=="/"){
        return 3;
    }else if(s==")"){
        return 4;
    }else{
        return -1;
    }

}
vector<string> zhong_to_hou(vector<string> ve){
    vector<string> hou;
    stack<string> st;
    for(int i=0;i<ve.size();i++){
        if(!is_c(ve[i])){
            hou.push_back(ve[i]);
        }else{
            if(st.empty() || ve[i]=="("){
                st.push(ve[i]);
            }else if(ve[i]==")"){
                while(st.top()!="("){
                    hou.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }else{
                int pri = get_pri(ve[i]);
                if(get_pri(st.top()) < pri){
                    st.push(ve[i]);
                }else{
                    while(!st.empty() && get_pri(st.top()) >= pri){
                        hou.push_back(st.top());
                        st.pop();
                    }
                    st.push(ve[i]);
                }

            }

        }
    }
    while(!st.empty()){
        hou.push_back(st.top());
        st.pop();
    }

    return hou;
}
int cal_post(vector<string> ve){
    stack<int> ret;
    for(int i=0;i<ve.size();i++){
        if(!is_c(ve[i])){
            ret.push(str_int(ve[i]));
        }else{
            int b = ret.top();
            ret.pop();
            int a = ret.top();
            ret.pop();
            if(ve[i]=="+"){
                ret.push(a+b);
            }else if(ve[i]=="-"){
                ret.push(a-b);
            }if(ve[i]=="*"){
                ret.push(a*b);
            }if(ve[i]=="/"){
                ret.push(a/b);
            }
        }
    }
    return ret.top();
}


int main()
{
    vector<string> ve = str_ve("78*(456+852)+87*9");
    vector<string> post = zhong_to_hou(ve);
    cout<<cal_post(post);
    return 0;
}

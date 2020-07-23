/*
 这道题的坑位。。。。查找键的时候，要带上后面的‘：’，要不然前50分只能拿20分
 */
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool isroot(string &jsonstr,size_t pos)
{
    //这里也是从L_Aster大神那里学到的，如果不加，扣10分
    //可以用来检测是不是key。。。。
    int pcnt=0;
    for(size_t i=0;i<pos;++i)
    {
        if(jsonstr[i]=='{') ++pcnt;
        if(jsonstr[i]=='}') --pcnt;
    }
    return pcnt==0;
}

void clean_str(string *str){
    // 这里是我自己写的函数，无法很好的处理有连续好多个‘/’的情况
    string *s = str;
    string::size_type s_t;
    // 这里除去空格和多余的’”‘
    string t = " ";
    while((s_t=s->find(t, 0)) != string::npos){
        s->erase(s_t,t.length());
    }
    // 这里处理 多余的 ’“‘
    string::size_type start_index;
    t = "\\";
    start_index = 0;
    while((s_t=s->find(t, start_index)) != string::npos){
        if(*(s->begin()+s_t+1) == '\\'){
            s->erase(s_t+1,t.length());
            start_index = s_t-1;
            continue;
        }
        start_index ++;
    }
    // 这里处理 ‘\"’
    t = "\\";
    start_index = 0;
    while((s_t=s->find(t, start_index)) != string::npos){
        if(*(s->begin()+s_t+1) == '"'){
            s->erase(s_t,t.length());
            start_index = s_t;
            continue;
        }
        start_index ++;

    }
}

string find_object(string str, string d_obj)
{

//    cout<<str<<"***"<<d_obj<<endl;
    size_t str_s=str.find(d_obj, 0), s1;
    if(str_s == string::npos) return "NOTEXIST";
    int count_l=0, count_l_r=0;
    string result;
    int i;
    for (i = str_s+d_obj.size()-1; i < str.length(); ++i) {
        if(str[i]=='{') count_l++;
        if(str[i]=='}') count_l_r++;
        if(count_l_r == count_l && count_l!=0) break;
    }
    if(count_l_r!=count_l) return "NOTEXIST";
    s1=str.find(d_obj, 0);
    s1 = str.find(":{", s1);
    result = str.substr(s1, i-s1+1);
    result.erase(0,1);
    result.erase(0,1);
    result.erase(result.length()-1, 1);
//    cout<<"result is:"<<result<<endl;
    return result+",";
}
string detect_str_result(string str_v, string str){
    size_t index_s=0, index_e;
    string result;
    string exam_s = str_v+"\":";
    index_s = str.find(exam_s, index_s);
    if(index_s == string::npos || !isroot(str,index_s)) return "NOTEXIST";  //这个位置使用isroot函数
    else{
        if(str[index_s+exam_s.length()]=='{') return "OBJECT";
        else{
            index_e = str.find("\",", index_s);
            result = str.substr(index_s+exam_s.length(), index_e-exam_s.length()-index_s+1);
            return result;
        }
    }
    // 这里是50分
}

string detect_str(vector<string> &str_v, string str){
    //如果有多层，则，反复提取出其中的object,然后传入只有一层的函数中
    for(int i=0;i<str_v.size()-1;i++){
        str = find_object(str, "\""+str_v[i]+"\":{");
        if(str.compare("NOTEXIST")==0) return "NOTEXIST";
    }
    return detect_str_result(str_v.back(), str);
}

void find_key(vector<string>&str_v, string exam_str){
    size_t index_s = 0, index_e;

    while((index_e = exam_str.find(".", index_s))!=string::npos){
        string key = exam_str.substr(index_s, index_e-index_s);
        str_v.push_back(key);
        index_s = index_e+1;
    }

    exam_str = exam_str.substr(index_s, exam_str.find("\n", index_s)-index_s);
    str_v.push_back(exam_str);
}
int main(){
    int n, m;
    string s;
    vector<string> strs_v;
    string str_all="", exam_str, key;

    /*
     这里是我扣10分的地方,如果用clearn_str函数，不但代码更加长，
     而且，不能很好的处理类似于"//////firstname"这样的键
     换成后面的代码，就很好了
    cin>>n>>m;
    cin.get();
    while(n--){
        getline(cin, exam_str);
        str_all += exam_str;
    }
    clean_str(&str_all);
    str_all.erase(0,1);
    str_all[str_all.length()-1] =  ',';
     */

    cin>>n>>m;
    cin.get();
    cin.get();
    for(int i=0;i<n;++i)
    {
        char ch;
        while((ch=cin.get())!='\n')
        {
            if(ch==' ') continue;  //去掉空格
            if(ch=='\\')
            {
                str_all+=cin.get();  //去掉‘\’，无论后面是啥，前面那个’\‘总是没用的
                continue;
            }
            str_all+=ch;
        }
    }
    str_all[str_all.length()-1] =  ',';
//    cout<<str_all<<endl;

    while(m--){
        cin>>exam_str;
        find_key(strs_v, exam_str);
        if(strs_v.size()==1)
        {
            //一层
            string exam = detect_str_result(strs_v[0], str_all);
            if(exam.compare("OBJECT")==0) cout<<"OBJECT"<<endl;
            else if(exam.compare("NOTEXIST") == 0) cout<<"NOTEXIST"<<endl;
            else {
                exam.erase(0,1);
                exam.erase(exam.length()-1,1);
                cout<<"STRING "<<exam<<endl;
            }
        }
        else{
            //多层
            string exam = detect_str(strs_v, str_all);
            if(exam.compare("OBJECT")==0) cout<<"OBJECT"<<endl;
            else if(exam.compare("NOTEXIST") == 0) cout<<"NOTEXIST"<<endl;
            else {
                exam.erase(0,1);
                exam.erase(exam.length()-1,1);
                cout<<"STRING "<<exam<<endl;
            }

        }
        strs_v.clear();
    }
    return 0;
}

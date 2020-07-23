#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

class MyString{
public:
    //split º¯Êý
    vector<string> split(string str,string s){
        vector<string> ret;
        if(s.size()==0){
            ret.push_back( str );
            return ret;
        }
        int pos = 0;
        while(  (pos = str.find(s) ) != string::npos ){
            if(pos>0){
                ret.push_back( str.substr(0,pos) );
            }
            str = str.substr( pos+ s.size() );
        }
        if(str.size() > 0){
            ret.push_back( str );
        }
        return ret;
    }
    //string ×ª int
    int str_int(string s){
        stringstream ss;
        int ret;
        ss<<s;
        ss>>ret;
        return ret;
    }

};


#endif // MYSTRING_H_INCLUDED

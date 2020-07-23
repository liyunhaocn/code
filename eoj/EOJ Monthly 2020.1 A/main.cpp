#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long LL;

#define debug(x) cout<<#x<<": "<<x<<endl;

string LL_str(LL a){
    stringstream ss;
    ss<<a;
    return ss.str();
}


int main()
{
    vector<string> nian0 = {"0","1","2","3","4","5","6","7","8","9"};
    vector<string> nian1 = {"0","1","2","3","4","5"};
    vector<string> nian2 = {"0","1","2","3","4","5","6","7","8","9"};
    vector<string> nian3 = {"0","1","2","3","4","5"};
    vector<string> yue = { "01","02","10","11","12" };
    vector<string> ri0 = {"1","2"};

    int indexnian0 = 2;
    int indexnian1 = 0;
    int indexnian2 = 2;
    int indexnian3 = 0;
    int indexyue = 0;
    int indexri0 = 1;

    int K = 200;
    scanf("%d",&K);
    for(int k=0;k<K;k++){

        indexri0 += 1;

        if( indexri0 == ri0.size()  ){
            indexri0 = 0;
            indexyue += 1;
        }

        if( indexyue == yue.size()  ){
            indexyue = 0;
            indexnian3 += 1;
        }

        if( indexnian3 == nian3.size()  ){
            indexnian3 = 0;
            indexnian2 += 1;
        }

        if( indexnian2 == nian2.size()  ){
            indexnian2 = 0;
            indexnian1 += 1;
        }

        if( indexnian1 == nian1.size()  ){
            indexnian1 = 0;
            indexnian0 += 1;
        }

        if( indexnian0 == nian0.size()  ){
            indexnian0 = 0;
        }


    }
    string ret =
        nian0[indexnian0] +
        nian1[indexnian1] +
        nian2[indexnian2] +
        nian3[indexnian3] +
        yue[indexyue]+
        ri0[indexri0];
        //debug(ret)
        cout<<ret;
        reverse(ret.begin(),ret.end());
        cout<<ret<<endl;

    return 0;
}

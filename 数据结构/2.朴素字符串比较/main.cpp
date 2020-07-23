#include <iostream>
#include<string.h>
using namespace std;
int NaivStrMatching(const string & T,const string & P)
{
    int p=0;
    int t=0;
    int plen=P.length();
    int tlen=T.length();
    if(tlen<plen)
        return -1;
    while(t<tlen && p<plen)
    {
        if(T[t]==P[p])
        {
            t++;
            p++;
        }
        else
        {
            t=t-p+1;
            p=0;
        }
    }
    if(p>=plen)
    {
        return (t-plen+1);
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout<<NaivStrMatching("sdfasdddd","as")<<endl;
    return 0;
}

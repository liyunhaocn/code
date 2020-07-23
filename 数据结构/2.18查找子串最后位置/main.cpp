#include <iostream>
#include<string.h>
using namespace std;
int NaivStrMatching(const string & T,const string & P)
{
    int p=0;
    int t=0;
    int plen=P.length();
    int tlen=T.length();
    int wei=0;
    if(tlen<plen)
    {
        return -1;
    }
    while(t<tlen)
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
        if(p==plen)
        {
            wei=t-plen+1;
            cout<<"Î»ÖÃ"<<wei<<"ÕÒµ½×Ó´®"<<endl;
        }
    }
    if(wei)
    {
        return wei;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cout<<NaivStrMatching("asdfasassssasdasdsfdsas","111")<<endl;
    return 0;
}

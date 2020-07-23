#include <iostream>
#include <string.h>
using namespace std;
int Strcmp(string S,string T)
{
    int i,j;
    int s=0;
    int t=0;
    int slen=S.length();
    int tlen=T.length();
    while(s<slen && t<tlen)
    {
        if(S[s]==T[t])
        {
            s++;
            t++;
        }
        else if(S[s]>T[t])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if(s==slen && t==tlen)
       return 0;
    else if(s==slen && t!=tlen)
       return -1;
    else
       return 1;

}

int main()
{
    /*
    char * a="a";
    char * b="A";
    cout<<strcmp(a,b);
    int aa='a';
    cout<<aa;
    aa='A';
    cout<<aa;
    */
    string a="ABCD";
    string b="AB";
    cout<<Strcmp(a,b)<<endl;
    return 0;
}

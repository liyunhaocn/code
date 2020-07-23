#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int temp = 3;
	for(int i=0;i<50;i++){
        cout<<temp<<", ";
        if(temp%2==1)temp = temp/2*3+2;
        else temp = temp/2*3+1;
	}
	return 0;
}


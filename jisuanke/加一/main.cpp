#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    int a[102];
    cin>>n;
    bool isGao = false;
    for(int i=1;i<n+1;i++){
        scanf("%d",&a[i]);
    }

    for(int j=n;j>0;j--){
        int he = a[j]+1;
        if(he==10){
            a[j] = 0;
            if(j==1){
                isGao = true;
            }
        }else{
            a[j] += 1;

            break;
        }

    }
    if(isGao){
        a[0]=1;
        a[1]=0;
    }

	int i = 1;
    if(isGao){
        i = 0;
    }
    for(;i<n+1;i++){
        printf("%d%c",a[i],i==n?'\n':' ');
    }
return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

int cal(int n){
    int counter = 0;
    while(n!=1){
        //cout<<n<<" ";
        counter ++;
        if(n%2==1){
            n = 3*n+1;
        }else{
            n /= 2;
        }

    }
    return counter + 1;
}

int arr[10001] ;
int main()
{
    int n;
    for(int i=1;i<10001 ;i++){
        arr[i]=cal(i);
    }
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int low = a;
        int high = b;
        if(a>b)swap(a,b);
        int m = arr[a];
        for(int i=a;i<=b;i++){
            m = max(arr[i],m);
        }
        //cout<< a <<" "<<b<<" "<< m <<endl;
        printf("%d %d %d\n",low,high,m);
    }

    return 0;
}

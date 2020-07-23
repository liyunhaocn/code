#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int temp;
    int sum = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        sum += temp*temp*temp*temp;
    }
    printf("%d\n",sum);
    return 0;
}

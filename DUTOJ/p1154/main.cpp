#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    int n;
    stack<int>st;
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n+1;i++){
        scanf("%d",&temp);
        temp *= i;
        st.push(temp);
    }
    while(!st.empty()){
        if(st.top()!=0){
            if(n>2){
                printf("%dx^%d+",st.top(),n-1);
            }else if(n==2){
                printf("%dx+",st.top());
            }else{
                printf("%d",st.top());
            }

        }
        st.pop();
        n--;
    }
    printf("\n");
    return 0;
}

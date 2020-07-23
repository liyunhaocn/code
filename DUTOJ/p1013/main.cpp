#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack1;
    stack<int> stackMin;
    int stack1Num = 0;
    int stackMinNum = 0;
    int T;
    int oper;
    int operNum;
    stackMin.push(0x3F3F3F3F);
    scanf("%d",&T);
    for(int i = 0;i < T;i ++){
        scanf("%d",&oper);
        if(oper == 0){
            scanf("%d",&operNum);
            stack1.push(operNum);
            stack1Num ++;
            if(operNum <= stackMin.top()){
                stackMin.push(operNum);
                stackMinNum ++;
            }
        }else if(oper == 1){
            if(stack1Num>0){
                printf("%d\n",stack1.top());
            }else{
                printf("ERROR!\n");
            }
        }else if(oper == 2){
            if(stackMinNum>0){
                printf("%d\n",stackMin.top());
            }else{
                printf("ERROR!\n");
            }

        }else if(oper == 3){
            if(stack1Num>0){
                int top = stack1.top();
                stack1.pop();
                stack1Num --;
                if(top == stackMin.top()){
                    stackMin.pop();
                    stackMinNum --;
                }
            }else{
                printf("ERROR!\n");
            }
        }

    }
    return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

int temp  = 0;
//��ֵ
void revise(int* a){
    *a = 1;
}
//����ֵ
void no_revise(int a){

    a = 3;
}
int main()
{

    printf("%d \n",temp);
    revise(&temp);
    printf("%d \n",temp);
    no_revise(temp);
    printf("%d \n",temp);
    return 0;
}

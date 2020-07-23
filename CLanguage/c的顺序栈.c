#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int m_maxSize;//maxsizeС��100��
    int m_top;
    int* m_arr;
};
void StackCreate(struct Stack* pstack1,int maxSize)
{
    pstack1->m_top=-1;
    pstack1->m_maxSize=maxSize;
    pstack1->m_arr=(int *)malloc(maxSize);
    printf("�ɹ�����ջ\n");
}
void Clear(struct Stack* pstack1)
{
    pstack1->m_maxSize=0;
    pstack1->m_top=-1;
    free(pstack1->m_arr);
    printf("�ѳɹ�ɾ��\n");
}
void Push(struct Stack* pstack1,const int num)
{
    if(IsFull(pstack1))
    {
        printf("����ջ���޷���ջ");
        exit(0);
    }
    else
    {
        pstack1->m_top++;
        pstack1->m_arr[pstack1->m_top]=num;
        printf("�ѳɹ���ջ\n");
    }
}
int Pop(struct Stack* pstack1)
{
    int item;
    if(IsEmpty(pstack1))
    {
        printf("ջ�ѿգ��޷�ɾ��\n");
        exit(0);
    }
    else
    {
        item=pstack1->m_arr[pstack1->m_top--];
        printf("�ɹ���ջ\n",item);
    }
    return item;
}
int Top(struct Stack* pstack1)
{
    int item;
    if(IsEmpty(*pstack1))
    {
        printf("ջ�ѿգ��޷�����\n");
        exit(0);
    }
    else
    {
        pstack1->m_arr[pstack1->m_top]=item;
    }
    return item;
}
int IsEmpty(struct Stack* pstack1)
{
    if(pstack1->m_top==-1)
        return 1;
    else
        return 0;
}
int IsFull(struct Stack* pstack1)
{
    if(pstack1->m_top==pstack1->m_maxSize)
        return 1;
    else
        return 0;
}
int IsTranspose(int* a,int n)
{
    int i,temp;
    struct Stack stack1;
    struct Stack* pstack1;
    pstack1=&stack1;
    StackCreate(pstack1,n/2);
    for(i=0;i<n/2;i++)
    {
        Push(pstack1,a[i]);
    }
    for((n%2==0)?(i=n/2):(i=n/2+1);!IsEmpty(pstack1);i++)
    {
        temp=Pop(pstack1);
        if(temp!=a[i])
        {
            Clear(pstack1);
            return 0;
        }
    }
    Clear(pstack1);
    return 1;
}
int main()
{
    int a[10]={1,2,2,1};
    printf("%d",IsTranspose(a,4));
    return 0;
}

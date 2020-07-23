#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    node * next;
};
void Initializate(node * & head,node * &  tail)
{
    head=(node *)malloc(sizeof(node));
    head->data=0;
    head->next=0;
    tail=head;
}
void InsertFromTail(node * & tail,int Data)
{
   node * p=(node *)malloc(sizeof(node));
   p->data=Data;
   p->next=0;
   tail->next=p;
   tail=p;
}

void InsertFromHead(node * & head,int Data)
{
   node * p=(node *)malloc(sizeof(node));
   p->data=Data;
   p->next=head->next;
   head->next=p;
}
void disp(node * p)
{
    p=p->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    node * p,*head,*tail;

    //p->data=9;
    Initializate(head,tail);
    for(int i=0;i<10;i++)
    InsertFromTail(tail,i);
    for(int i=10;i<20;i++)
    InsertFromHead(head,i);
    disp(head);

    //printf("%d",tail->data);

    return 0;
}

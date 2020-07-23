#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    int data;
    node * next;
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

node* instail( int data,node* tail){
    tail->next = new node(data);
    tail = tail->next;
    tail->next = nullptr;
    return tail;
}

void inshead(int data, node* head){
    node* temp = new node(data);
    temp->next = head -> next;
    head->next = temp;
}

void dis(node* head){
    head = head->next;
    while(head != nullptr ){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}


void myIns(int data,node* head){
    head = head->next;
    while(head != nullptr ){
        if(head->data<=data && head->next->data > data){
            node* temp = new node(data);
            temp->next = head ->next;
            head->next = temp;
            break;
        }else{
            head = head->next;
        }
    }
}

int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    int n;

    while(scanf("%d",&n) != EOF){
        head = tail = new node(-1);
        head ->next = nullptr;
        for(int i=0;i<n;i++){
            //inshead(i,head);
            //tail = instail(i,tail);

            int temp;
            scanf("%d",&temp);
            if( head->next == nullptr){
                tail = instail( temp ,tail );
            }else if(temp <= head->next->data){
                inshead(temp,head);
            }else if( temp >= tail->data ){
                tail = instail( temp ,tail);
            }else{
                myIns(temp,head);
            }

        }
        dis(head);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
}*head;
void create(int a[],int n){
    int i;
    Node *t,*last;
    head = new Node();
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=new Node();
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int length(Node *p){
    int len =0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
void insert(Node *p , int ind ,int x){
    Node *t;
    int i;
    if(ind<0||ind>length(p))
        return ;
    if(ind ==0){
        t = new Node();
        t->data = x;
        if(head==NULL){
            head =t;
            head->next = head;
        }
        else{
            while(p->next!=head) 
                p=p->next;
            p->next=t;
            t->next =head;
            head =t;
        }
    }
    else{
        for(i=0;i<ind-1;i++)
            p=p->next;
        t = new Node();
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
void display(Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=head);
}
int main(){
    int a[]={1,53,4,5,7};
    create(a,5);
    insert(head,2,10);
    display(head);
    return 0;
}
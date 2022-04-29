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
int _delete(int pos){
    Node *p=head,*q;
    int x = -1;
    if(pos<0 || pos >length(p))
        return x;
    if(pos==1){
        p=head;
        while(p->next!=head)
            p=p->next;
        x = head->data;
        if(p==head){
            delete head;
            head = NULL;
        }
        else{
            p->next = head->next;
            delete head;
            head=p->next;
        }
    }
    else{
        p=head ; 
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        x=q->data;
        delete q;
    }
    return x;
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
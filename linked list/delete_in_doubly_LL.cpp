#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
}*first=NULL;
void create(int a[],int n){
    Node *t,*last;
    first = new Node();
    first->data = a[0];
    first->prev = first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t = new Node();
        t->data=a[i];
        t->next = last->next;
        t->prev = last;
        last->next=t;
        last=t;
    }
}
void display(Node *p){
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}
int len(Node* p){
    int len =0 ;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
int _delete(Node *p,int pos){
    int x=-1;
    if(pos<1 || pos>len(p))
        return x;
    if(pos==1){
        first = first->next;
        if(first) first->prev = NULL;
        x=p->data;
        delete p;//free(p);
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
}
void insert(int val,int pos){
    Node *p=first;
    if(pos<0 || pos > len(p))
        return ;
    if(pos==1){
        Node *t = new Node();
        t->data = val;
        t->next = first;
        t->prev =NULL;
        first->prev=t;
        first = t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        Node *t= new Node();
        t->data = val;
        t->next = p->next;
        if(p->next)
            p->next->prev=t;
        p->next = t; 
    }
}
int main(){
    int a[]={1,2,3,4,5};
    create(a,5);
    _delete(first,2);
    display(first);
    return 0;
}
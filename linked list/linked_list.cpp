#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
class Linkedlist{
    Node *first;
    public:
        Linkedlist(){first = NULL;}
        Linkedlist(int A[],int n);
        ~Linkedlist();

        void Display();
        void Insert(int ind,int val);
        int _Delete_(int index);
        int Length();
};
Linkedlist::Linkedlist(int A[],int n){
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
Linkedlist::~Linkedlist(){
    Node *p=first;
    while (first)
    {
        first=first->next;
        delete p;
        p=first;
    }    
}
void Linkedlist::Display(){
    Node *p=first;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }    
}
int Linkedlist::Length(){
    Node *p=first;
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    return cnt;
}
void Linkedlist::Insert(int ind,int val){
    Node *p=first;
    Node *t;
    int i;
    if(ind<0 || ind>Length())
        return;
    t=new Node();
    t->data=val;
    if(ind==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<ind-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int Linkedlist::_Delete_(int ind){
    Node *p,*q=NULL;
    int x=-1;
    if(ind< 1|| ind>Length())
        return -1;
    if(ind==1){
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        p = first;
        for(int i=0;i<ind-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int main(){
    int a[]={1,2,3,4,5};
    Linkedlist l(a,5);
    l.Display();
    return 0;
}
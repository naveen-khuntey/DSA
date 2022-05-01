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
int main(){
    int a[]={1,2,3,4,5};
    create(a,5);
    display(first);
    return 0;
}
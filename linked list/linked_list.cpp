#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node *next;
};
template<class T>
class Linkedlist{
    Node<T> *first;
    public:
        Linkedlist(){first = NULL;}
        Linkedlist(T A[],int n);
        ~Linkedlist();

        void Display();
        void Insert(int ind,T val);
        T _Delete_(int index);
        int Length();
};
template<class T>
Linkedlist<T>::Linkedlist(T A[],int n){
    int i;
    struct Node<T> *t, *last;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
template<class T>
Linkedlist<T>::~Linkedlist(){
    Node<T> *p=first;
    while (first)
    {
        first=first->next;
        delete p;
        p=first;
    }    
}
template<class T>
void Linkedlist<T>::Display(){
    Node<T> *p=first;
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }    
}
template<class T>
int Linkedlist<T>::Length(){
    Node<T> *p=first;
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
    return cnt;
}
template<class T>
void Linkedlist<T>::Insert(int ind,T val){
    Node<T> *p=first;
    Node<T> *t;
    int i;
    if(ind<0 || ind>Length())
        return;
    t=new Node<T>;
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
template<class T>
T Linkedlist<T>::_Delete_(int ind){
    Node<T> *p,*q=NULL;
    T x=-1;
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
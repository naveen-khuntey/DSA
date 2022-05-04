#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class _stack{
    public:
        Node *top;
        _stack(){
            top = NULL;
        }
        void push(int x){
            Node *t = new Node;
            if(t==NULL) 
                cout<<"stack overflow";
            else{
                t->data=x;
                t->next=top;
                top=t;
            }
        }
        void pop(){
            if(top==NULL)
                cout<<"stack underflow";
            else{
                Node *t=top;
                top=top->next;
                free(t);
            }
        }
        int peek(int pos){
            Node *t = top;
            for(int i=0;i<pos-1;i++)
                t=t->next;
            if(t==NULL)
                cout<<"invalid";
            else
                return t->data;
            return -1;
        }
        bool isEmpty(){
            if(top==NULL)
                return 1;
            else
                return 0;
        }
        bool isFull()
        {
            Node *t = new Node;
            if(t==nullptr)
                return 1;
            else
                return 0; 
        }
        int stacktop(){
            if(top==NULL)
                return -1;
            else
                return top->data;   
        }
        void display(){
            Node *p;
            p=top;
            while(p!=NULL){
                cout<<p->data<<" ";
                p=p->next;
            }
        }
        ~_stack(){
            while(top!=NULL){
                Node *t=top;
                top=top->next;
                free(t);
            }
        }
};

int main(){
    _stack st;
    int size;
    cout<<"size of stack = ";
    cin>>size;
    for(int i=0;i<size;i++){
        int z;
        cin>>z;
        st.push(z);
    }
    st.display();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class _stack{
    public:
    int size;
    int top;
    int *s;
    _stack(){
        cout<<"Enter size ";
        cin>>size;
        s = new int[size];
        top=-1;
    }
};
void push(_stack *st,int val){
    if(st->top==st->size-1)
        cout<<"stack overflow\n";
    else{
        st->top++;
        st->s[st->top] = val;
    }
}
void pop(_stack *st){
    if(st->top==-1)
        cout<<"stack underflow\n";
    else{
        st->top--;
    }
}
int peek(_stack st,int pos){
    int x=-1;
    if(st.top-pos+1<0)
        cout<<"invalid";
    else
        x=st.s[st.top-pos+1];
    return x;
}
int stacktop(_stack st){
    if(st.top==-1)
        return -1;
    else    
        return st.s[st.top];
}
bool isEmpty(_stack st){
    if(st.top==-1)
        return 1;
    else
        return 0;
}
bool isFull(_stack st){
    if(st.top==st.size-1)
        return 1;
    else
        return 0;
}
void display(_stack st){
    while(st.top!=-1){
        cout<<st.s[st.top--]<<" ";
    }
}
int main(){
    _stack st;
    for(int i=0;i<st.size;i++){
        int x;
        cin>>x;
        push(&st,x);
    }
    display(st);
}
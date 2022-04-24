#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    struct Node *next;
} *first = NULL;
int length(struct Node *P){
    int cnt=0;
    while(P!=NULL){
        cnt++;
        P=P->next;
    }
    return cnt;
}
void insert(int ind,int val){
    Node *p=first;
    Node *t;
    int i;
    if(ind<0||ind>length(p))
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
void Display(Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main()
{
    Node *temp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(i,x);
    }
    Display(first);
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Node
{
    public:
    int data;
    struct Node *next;
} *first = NULL,*last = NULL;
void insert_last(int val){
    Node *t = new Node();
    t->data=val;
    t->next=NULL;
    if(first==NULL){
        first = last =t;
    }
    else{
        last->next=t;
        last=t;
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
signed main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert_last(x);
    }
    Display(first);
    cout<<endl;
    return 0;
}
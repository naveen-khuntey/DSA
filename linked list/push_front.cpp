#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
} *first = NULL;
/*fush at front */ 
void push_front(Node **p,int n){
    Node *new_node = new Node();
    new_node->data=n;
    new_node->next=(*p);
    (*p) = new_node;
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main()
{
    Node *temp=new Node;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        push_front(&first,x);
    }
    Display(first);
    return 0;
}
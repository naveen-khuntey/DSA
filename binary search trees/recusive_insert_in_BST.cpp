#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* lchild;
    int data;
    Node* rchild;
}*root=NULL;
void insert(int key){
    Node *t = root;
    Node *r,*p;
    if(root==NULL){
        p = new Node;
        p->data = key;
        p->lchild=p->rchild=NULL;
        root =p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            break;
    }
    p = new Node;
    p->data = key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}
/*----------------------------recursive insert---------------------*/
Node* Rinsert(Node *p,int key){
    if(p==NULL)
    {
        Node* t = new Node;
        t->data = key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=Rinsert(p->rchild,key);
    return p;

}
/*-----------------------------------------------------------------*/
void inorder(Node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(x);
    }
    inorder(root);
}
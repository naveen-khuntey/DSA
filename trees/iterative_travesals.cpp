//IT is a Binary Tree
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Tree{
    Node *root;
    public:
        Tree() { root = NULL; }
        void CreateTree();
        void Preorder() { Preorder(root); }
        void Preorder(Node *p);
        void Postorder() { Postorder(root); }
        void Postorder(Node *p);
        void Inorder() { Inorder(root); }
        void Inorder(Node *p);
        void Levelorder() { Levelorder(root); }
        void Levelorder(Node *p);
        int Height() { return Height(root); }
        int Height(Node *root);
};
void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    queue<Node*> q;
    printf("Eneter root value ");
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        printf("eneter left child of %d ", p->data);
        cin>>x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("eneter right child of %d ", p->data);
        cin>>x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}
void Tree::Preorder(Node *p)
{
    stack<Node*> st;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            cout<<p->data<<" ";
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            p=p->rchild;
        }
    } 
}
void Tree::Inorder(Node *p)
{
    stack<Node*> st;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    } 
}
void Tree::Postorder(Node *p)
{
    stack<Node*> st; long long temp;
    while(p!=NULL || !st.empty()){
        if(p!=NULL){
            st.push(p);
            p = p->lchild;
        }
        else{
            temp =(long long)st.top();
            st.pop();
            if(temp>0){
                st.push(((Node*)-temp));
                p = ((Node*)temp)->rchild;
            }
            else{
                cout<<((Node*)temp)->data<<" ";
                p = NULL;
            }    
        }
    } 
}
void Tree::Levelorder(Node *root)
{
    queue<Node*> q;
    cout<<(root->data)<<" ";
    q.push(root);
    while (!q.empty())
    {
        root = q.front(); 
        q.pop();
        if (root->lchild)
        {
            cout<<(root->lchild->data)<<" ";
            q.push(root->lchild);
        }
        if (root->rchild)
        {
            cout<<(root->rchild->data)<<" ";
            q.push(root->rchild);
        }
    }
}
int Tree::Height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{
    Tree t;
    t.CreateTree();
    cout <<"Preorder ";
    t.Preorder();
    cout << endl;
    cout <<"Inorder ";
    t.Inorder();
    cout<<endl;
    cout<<"Postorder ";
    t.Postorder();
    cout<<endl;
    return 0;
}
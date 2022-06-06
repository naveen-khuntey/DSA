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
        int countNode(){ return countNode(root);};
        int countNode(Node *p);
        int count(){ return count(root);};
        int count(Node *p);
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
int Tree :: countNode(Node *p){
    if(p!=NULL)
    {
        return (countNode(p->lchild) + countNode(p->rchild) + 1);
    }
    return 0;
}
/*condition for counting different type of Nodes
1. Leaf Nodes(deg 0)    = if(!p->lchild && !p->rchild)
2. Node with deg 2 only = if(p->lchild && p->rchild)
3. Node with deg 2 or 1 = if(p->lchild || p->rchild)
4. Node with deg 1 only = if(p->lchild!=NULL ^ p->rchild!=NULL)*/
int Tree :: count(Node *p){
    if(p==NULL)
        return 0;
    if(!p->lchild && !p->rchild)// condtion for which you want to calculate  
        return (count(p->lchild) + count(p->rchild) + 1);
    return (count(p->lchild) + count(p->rchild));
}
int main()
{
    Tree t;
    t.CreateTree();
    cout<<t.countNode();
    cout<<endl;
    cout<<t.count();
    cout<<endl;
    return 0;
}
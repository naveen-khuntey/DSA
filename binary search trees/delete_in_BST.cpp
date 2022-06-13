#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;
void insert(int key)
{
    Node *t = root;
    Node *r, *p;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            break;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
Node *InPre(Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}
Node *InSucc(Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}
/*-------------------------delete----------------------*/
Node *_delete(Node *p, int key)
{
    Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lchild = _delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = _delete(p->rchild, key);
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = _delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = _delete(p->rchild, q->data);
        }
    }
    return p;
}
/*-----------------------------------------------------------*/
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);
    }
    inorder(root);
}
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
void insert(int val){
    Node *p=first;
    Node *q = NULL;
    while(p&&p->data<val){
        q=p;
        p=p->next;
    }
    Node *t = new Node();
    t->data=val;
    t->next=q->next;
    q->next=t;
}
int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 35, 38, 42};
    create(A, 8);
    Display(first);
    insert(9);
    Display(first);
    return 0;
}
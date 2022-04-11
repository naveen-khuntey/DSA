#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int max(Node *p){
    int maxx = INT32_MIN;
    while(p){
        if(p->data>maxx)
            maxx = p->data;
        p=p->next;
    }
    return maxx;
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
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    Display(first);
    int cnt = max(first);
    cout<<endl<<cnt;
    return 0;
}
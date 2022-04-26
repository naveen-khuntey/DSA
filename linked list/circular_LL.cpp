#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
}*head;
void create(int a[],int n){
    int i;
    Node *t,*last;
    head = new Node();
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=new Node();
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(Node *h){
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=head);
}
int main(){
    int a[]={1,53,4,5,7};
    create(a,5);
    display(head);
    return 0;
}
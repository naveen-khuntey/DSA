#include<bits/stdc++.h>
using namespace std;
void funb(int n);
void funa(int n){
    if(n>0){
        cout<<n;
        funb(n-1);
    }
}
void funb(int n){
    if(n>0){
        cout<<n;
        funa(n/2);
    }
}
int main(){
    int n;
    cin>>n;
    funa(n);
    return 0;
}
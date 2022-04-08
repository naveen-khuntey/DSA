/*e^x = 1+ x/1 + x^2/2! + x^3/3! + ... + x^n/n!*/ 
#include<bits/stdc++.h>
using namespace std;
int expo(int x,int n){
    static int s =1;
    if(n==0)
        return s;
    s = 1+ (x/n)*s;
    return expo(x,n-1);  
}
int main(){
    int n,x;
    cin>>x>>n;
    cout<<expo(x,n);
    return 0; 
}
/*m to power n using recursion*/ 
#include<bits/stdc++.h>
using namespace std;
int pow(int m,int n)
{
    if(n==0)
        return 1;
    else
        return pow(m,n-1)*m;
}
//faster
int pow1(int m,int n){
    if(n==0)
        return 1;
    if(n&1)
        return m*pow1(m*m,(n-1)/2);
    else
        return pow1(m*m,n/2);
}
int main(){
    int m,n;
    cin>>m>>n;
    int k = pow(m,n);
    int l = pow(m,n);
    cout<<k<<" "<<l; 
}
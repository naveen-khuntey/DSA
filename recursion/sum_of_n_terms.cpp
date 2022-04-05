/*Sum of n terms using recursion*/
#include<bits/stdc++.h>
using namespace std;
int modulo = 99587344;
//o(n)
int sum(int n){
    if(n>0)
        return sum(n-1) + n;
    else
        return 0; 
}
// o(1)
int sum(int n,int mod){
    mod = modulo;
    return (n*(n+1)/2)%mod;
}
int main(){
    int n;
    cin>>n;
    int k = sum(n);
    cout<<k;
    return 0 ;
} 
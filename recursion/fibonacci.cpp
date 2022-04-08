/*fibonacci using memoization*/ 
#include<bits/stdc++.h>
using namespace std;
vector<int> F;
int fib(int n){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fib(n-2);
        if(F[n-1]==-1)
            F[n-1] = fib(n-1);
        F[n] = F[n-1] + F[n-2];
        return F[n];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        F[i] = -1;
    }
}
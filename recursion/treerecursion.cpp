#include<bits/stdc++.h>
using namespace std;
void fun(int n){
    if(n>0){
        cout<<n<<" ";
        fun(n-1);
        cout<<n<<" ";
        fun(n-1);
    }
}
int main(){
    int n;
    cin>>n;
    fun(n);
    return 0;
}
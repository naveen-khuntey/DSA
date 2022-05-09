//not including brackets and right-to-left associativity operators
#include<bits/stdc++.h>
using namespace std;
int pre(char x){
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    return 0;
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}
string InToPost(string infix){
    stack<char> st;
    st.push('#');
    int len = infix.size();
    string postfix="";
    int i=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix.push_back(infix[i++]);
        }
        else{
            if(pre(infix[i])>pre(st.top()))
                st.push(infix[i++]);
            else{
                char ch = st.top();
                st.pop();
                postfix.push_back(ch);
            }
        }
            
    }
    while(!(st.empty())){
        char ch = st.top();
        st.pop();
        postfix.push_back(ch);
    }
    postfix.pop_back();
    return postfix;
}
int main(){
    string s;
    s="a+b*c";
    string postfix = InToPost(s);
    cout<<postfix;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}
int Eval(string postfix){
    stack<char> st;
    for(int i=0;i<postfix.size();i++){
        if(isOperand(postfix[i]))
            st.push((postfix[i]-'0'));
        else{
            char x1 = st.top();st.pop();
            char x2 = st.top();st.pop();
            char r ;
            switch (postfix[i])
            {
                case '+': r = x1+x2;break;
                case '-': r = x1-x2;break;
                case '*': r = x1*x2;break;
                case '/': r = x1/x2;break;
                default: break;
            }
            //string j = to_string(r);
            st.push(r);
        }
    }
    return st.top();
}
int main(){
    string s = "234*+82/-";
    int k = Eval(s);
    cout<<k;
    return 0;
}
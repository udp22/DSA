#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s){
    // int i=0;
    stack<string>st;

    for(char c:s){
        
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp="("+t2+c+t1+")";
            st.push(temp);
        }
    }

    return st.top();
}

int main() {

    string s="ab*c+";
    cout<<postfixToInfix(s)<<endl;

    return 0;
}
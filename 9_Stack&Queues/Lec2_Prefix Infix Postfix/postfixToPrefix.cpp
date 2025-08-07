#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s){
    if(s.empty()) {
        return "";
    }
    
    stack<string>st;

    for(char c:s){
        if(isalnum(c)){
            st.push(string(1,c));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp=c+t2+t1;
            st.push(temp);
        }

    }

    if (!st.empty()) {
        return st.top();
    }
    return "";
}

int main() {

    string s="ABC/-AK/L-*";
    cout<<postfixToPrefix(s)<<endl;

    return 0;
}
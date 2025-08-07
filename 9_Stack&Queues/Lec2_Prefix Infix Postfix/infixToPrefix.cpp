#include <bits/stdc++.h>
using namespace std;

string firstReverse(string s){
    reverse(s.begin(), s.end());
    for(size_t i=0;i<s.length();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    return s;
}

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPrefix(string s){
    string str = firstReverse(s);
    stack<char> st;
    string ans="";

    for(char c:str){
        if(isalnum(c)){
            ans+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        else{ // operator
            while(!st.empty() && precedence(c) < precedence(st.top())){
                ans+=st.top();
                st.pop();
            }
            // for right-associative '^'
            if(c == '^'){
                while(!st.empty() && precedence(c) == precedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s="(A+B)*(C-D)";
    cout<<infixToPrefix(s)<<endl;
    return 0;
}

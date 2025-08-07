#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s){

    int n=s.length();
    stack<string>st;

    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp = t1+t2+s[i];
            st.push(temp);
        }
    }
    return st.top();
}

int main() {

    string s="*-A/BC-/AKL";
    cout<<prefixToPostfix(s)<<endl;

    return 0;
}
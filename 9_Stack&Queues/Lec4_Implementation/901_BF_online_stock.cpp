#include<bits/stdc++.h>
using namespace std;

//Giving TLE on last second test case 

class StockSpanner {
public:
    stack<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stack<int>temp=st;
        int ans=1;
        while(!temp.empty() && temp.top()<=price){
            ans++;
            temp.pop();
        }
        st.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
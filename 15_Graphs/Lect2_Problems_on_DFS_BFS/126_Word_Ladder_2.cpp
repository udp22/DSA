#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Word Ladder 2

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        q.push({beginWord});
        int level=0;
        vector<vector<string>>ans;
        
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word=vec.back();

            if(word==endWord){
                
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
                else if(ans[0].size()<vec.size()){
                    break;
                }
            }

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedOnLevel.push_back(word);
                    }
                }
                word[i]=original;
            }

            
        }

        return ans;
    }
};
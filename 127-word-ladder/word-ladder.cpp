#include<bits/stdc++.h>
class Solution {
public:
    int ladderLength(string src, string dest, vector<string>& words) {
        queue<pair<string,int>> q;
        q.push({src,1});
        unordered_set<string> s(words.begin(),words.end());
        s.erase(src);
        while(!q.empty())
        {
            string org=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(org==dest) return steps;
            for(int i=0;i<org.size();i++)
            {
                char ch=org[i];
                for(char c='a';c<='z';c++)
                {
                    org[i]=c;
                    if(s.find(org)!=s.end()) {q.push({org,steps+1}); s.erase(org);}
                }
                org[i]=ch;
            }
        }
        return 0;
    }
};
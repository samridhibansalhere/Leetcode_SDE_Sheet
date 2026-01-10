class Solution {
public:
void dfs(string src,string dest,vector<string>&v,vector<vector<string>> &ans,unordered_map<string,int>& mp){
    if(dest==src){reverse(v.begin(),v.end()); ans.push_back(v); reverse(v.begin(),v.end()); return;}
    int steps=mp[dest];
    for(int i=0;i<dest.size();i++)
    {
        char ch=dest[i];
        for(int j='a';j<='z';j++)
        {
            dest[i]=j;
            if(mp.find(dest)!=mp.end() && mp[dest]+1==steps) {v.push_back(dest); dfs(src,dest,v,ans,mp); v.pop_back();}
        }
        dest[i]=ch;
    }
}
    vector<vector<string>> findLadders(string src, string dest, vector<string>& words) {
        queue<string> q;
        unordered_set<string> st(words.begin(),words.end());
        q.push(src);
        unordered_map<string,int> mp;
        mp[src]=1;
        st.erase(src);
        while(!q.empty())
        {
            string word=q.front();
            int steps=mp[word];
            q.pop();
            if(word==dest) break;
            for(int i=0;i<word.size();i++)
            {
                char ch=word[i];
                for(int j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(st.count(word)) {q.push(word); st.erase(word); mp[word]=steps+1;}
                }
                word[i]=ch;
            }
        }
        vector<vector<string>> ans;
        if(mp.find(dest)!=mp.end()){vector<string> v; v.push_back(dest); dfs(src,dest,v,ans,mp);}
        return ans;
    }
};
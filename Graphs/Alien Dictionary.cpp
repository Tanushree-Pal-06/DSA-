class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        for(int i=0;i<words.size()-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            bool found = false;
            
            for(int ptr = 0; ptr < len; ptr++) {
                if(s1[ptr] != s2[ptr]) {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size())
                return "";
        }
        int cnt=0;
        vector<int> present(26, 0);
        for(auto word : words){
            for(char ch : word){
                if(present[ch-'a'] == 0){
                present[ch-'a'] = 1;
                cnt++;
                }
            }
        }
        vector<int> indegree(26,0);
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        string seq="";
        if(ans.size()!=cnt)return seq;
        
        for(auto ch: ans){
            seq+=char(ch+'a');
        }
        return seq;
    }
};

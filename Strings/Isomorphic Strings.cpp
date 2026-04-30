class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp, spp;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]==t[i] && spp[t[i]]==s[i])continue;
                else return false;
            }
            else {
                mpp[s[i]]=t[i];
                if(spp.find(t[i])!=spp.end()) return false;
                else spp[t[i]]=s[i];
            }
        }
        return true;
    }
};

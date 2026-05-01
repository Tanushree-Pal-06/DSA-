class Solution {
public:
    static bool descSort(pair<char,int> &a, pair<char,int>  &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        string ans="";
        unordered_map <char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
    
        vector<pair<char,int>> vec;
        for(auto it :freq){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),descSort);
        for( auto it: vec){
            while(it.second>0){
                ans+=it.first;
                it.second--;
            }
           
        }
        return ans;
    }
};

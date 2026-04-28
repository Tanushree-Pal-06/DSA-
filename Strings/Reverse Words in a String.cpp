class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{

                if(!word.empty()){
                reverse(word.begin(),word.end());
                ans+=word;
                ans+=" ";
                word="";
                }
                else{
                    continue;
                }
                
            }
        }
        if(!word.empty()){
        reverse(word.begin(),word.end());
        ans+=word;
        }
        if(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};

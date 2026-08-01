class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto[word,steps]=q.front();
            if(word==endWord)return steps;
            q.pop();
            for(int i=0;i<word.size();i++){
            char org=word[i];
              for( char ch='a'; ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,steps+1});
                    st.erase(word);
                }
                word[i]=org;
            }
            }
        }
        return 0;
    }
};

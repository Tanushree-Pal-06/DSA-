class Solution {
  public:
    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {

        unordered_set<string> st(words.begin(), words.end());

        vector<vector<string>> ans;
        queue<vector<string>> q;

        q.push({s});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(s);

        int level = 1;

        while (!q.empty()) {

            int sz = q.size();

            // Process only the current level
            for (int j = 0; j < sz; j++) {

                vector<string> vec = q.front();
                q.pop();

                string word = vec.back();

                // If target is reached
                if (word == e) {

                    if (ans.empty()) {
                        ans.push_back(vec);
                    }
                    else if (ans[0].size() == vec.size()) {
                        ans.push_back(vec);
                    }

                    continue;
                }

                // If we already found shortest answers,
                // don't generate longer sequences
                if (!ans.empty() && vec.size() >= ans[0].size()) {
                    continue;
                }

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        word[i] = c;

                        if (st.count(word)) {

                            vec.push_back(word);
                            q.push(vec);

                            // Mark this word as used on this level
                            usedOnLevel.push_back(word);

                            vec.pop_back();
                        }
                    }

                    word[i] = original;
                }
            }

            // Now current level is completely processed.
            // Remove all words used in this level.
            for (auto &it : usedOnLevel) {
                st.erase(it);
            }

            usedOnLevel.clear();

            level++;
        }

        return ans;
    }
};

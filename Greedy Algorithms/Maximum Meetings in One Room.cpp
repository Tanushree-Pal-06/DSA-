class Solution {
  public:
  
    struct Meeting{
        int finish;
        int start;
        int index;
    };
    
    static bool cmp(Meeting a , Meeting b){ // acc to note (sorting based on finish time)
        if(a.finish==b.finish){
            return a.index<b.index ;// smaller index goes first
        }
        return a.finish<b.finish;
        
    }
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<int> ans;
        vector<Meeting> meetings;
        for(int i=0;i<s.size();i++){
            meetings.push_back({f[i],s[i],i+1});
        }
        sort(meetings.begin(),meetings.end(),cmp);
        int last=-1;
        for(int i=0;i<meetings.size();i++){
            if(last==-1) {
                ans.push_back(meetings[i].index);
                last=i;
            }
            if(meetings[i].start>meetings[last].finish){
                ans.push_back(meetings[i].index);
                last=i;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

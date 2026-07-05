class Solution {
  public:
  
    struct Job{
        int i;
        int dead;
        int profit;
    };
    
    static bool cmp(Job a ,Job b){
        return a.profit>b.profit;
    }
    
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<Job> jobs;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({i,deadline[i],profit[i]});
        }
        int ans=0;
        int totalProfit = 0;
        sort(jobs.begin(),jobs.end(),cmp);
        int maxdl=0;
        for(int i=0;i<deadline.size();i++){
            maxdl=max(maxdl,deadline[i]);
        }
        vector<int> slots(maxdl,-1);
        
        for(int i=0;i<jobs.size();i++){
            for(int j=jobs[i].dead-1;j>=0;j--){
                if(slots[j]==-1) {
                    slots[j]=1;
                    ans++;
                    totalProfit += jobs[i].profit;
                    break;
                }
                
            }
        }
        return {ans, totalProfit};
    }
};

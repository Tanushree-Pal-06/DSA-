class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        //{step,node}
        vector<int> dist(1000,1e9);
        if(start == end) return 0;
        dist[start]=0;
        int mod=1000;
        queue<pair<int,int>> q;
        q.push({0,start});
        while(!q.empty()){
            auto [step,node]=q.front();
            q.pop();
            for(int i=0;i<arr.size();i++){
                int num=(1LL*node*arr[i])%mod;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                    if(num==end)return step+1;
                    q.push({step+1,num});
                    
                }
            }
        }
        return -1;
        
    }
};

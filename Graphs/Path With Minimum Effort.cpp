class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        
        //diff vector
        vector<vector<int>> diff(n,vector<int> (m,1e9));
        diff[0][0]=0;
        pq.push({0,{0,0}});
        
        //for 4 directions
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};


        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dif=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1)return dif;
            for(int i=0;i<4;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int d=abs(heights[row][col]-heights[newr][newc]);
                    if(max(d,dif)<diff[newr][newc]){
                        diff[newr][newc]=max(d,dif);
                        pq.push({max(d,dif),{newr,newc}});
                    }
                }
            }
        }
        return 0; //unreachable
    }
};

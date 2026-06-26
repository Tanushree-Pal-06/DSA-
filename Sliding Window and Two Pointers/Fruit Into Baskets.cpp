class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int maxfruit=0;
        int cnt=0;
        unordered_map<int,int> mpp;
        while(r<fruits.size()){
            
            if(mpp.find(fruits[r])==mpp.end()){
                cnt++;
                
                }
            mpp[fruits[r]]++;    
            
            
            if(cnt>2){
                while(cnt>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0){
                        mpp.erase(fruits[l]);
                        cnt--;
                        }

                    l++;    
                }
            }
            else maxfruit=max(maxfruit,r-l+1);
            
            r++;
        }
        return maxfruit;
    }
};

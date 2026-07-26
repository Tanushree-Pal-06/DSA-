class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> ahead(2,0), curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
              if(buy){
                profit=max(-prices[i]+ahead[0],0+ahead[1]);
              }
              else{
                profit=max(prices[i]+ahead[1],0+ahead[0]);
              }
              curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        
        double ans=0;
        int i=prices.size()-1;
        int j=discounts.size()-1;
        while(i>=0 && j>=0){
            double price=(prices[i]*(100.0-discounts[j]))/100.0;
            ans+=price;
            i--;
            j--;
        }
        while(i>=0){
            ans+=prices[i];
            i--;
        }
        return ans;
    }
};

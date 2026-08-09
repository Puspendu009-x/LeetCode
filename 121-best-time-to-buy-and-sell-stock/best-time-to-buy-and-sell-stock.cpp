class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=prices[0];
        int maxpro=0;
        int pre=profit;
        for(int i=1;i<n;i++){
            pre=profit;
            profit=prices[i]-profit;
            if(profit>maxpro){
                maxpro=profit;
            }
            if(profit<0){
                profit=prices[i];
            }
            else{
                profit=pre;
            }
        }
        return maxpro;
    }
};
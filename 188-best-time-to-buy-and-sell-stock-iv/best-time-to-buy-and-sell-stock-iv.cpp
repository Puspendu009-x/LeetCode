class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>after(2*k+1,0);
        vector<int>curr(2*k+1,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int t=2*k-1;t>=0;t--){
                if(t%2==0)
                curr[t]=max(-prices[ind]+after[t+1],after[t]);
                else
                curr[t]=max(prices[ind]+after[t+1],after[t]);
            }
            after = curr;
        }
        return after[0];
    }
};
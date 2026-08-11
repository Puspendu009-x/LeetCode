class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<double>> dp(n + 1, vector<double>(5, 0));

        for(int ind=n-1;ind>=0;ind--){
            for(int t=3;t>=0;t--){
                if(t%2==0)
                dp[ind][t]=max((-prices[ind]+dp[ind+1][t+1]),dp[ind+1][t]);
                else
                dp[ind][t]=max((prices[ind]+dp[ind+1][t+1]),dp[ind+1][t]);
            }
        }
        return (int)dp[0][0];
    }
};
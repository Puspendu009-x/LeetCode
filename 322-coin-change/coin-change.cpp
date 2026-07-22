class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1, 0);
        vector<int>curr(amount+1, 0);

        for(int T = 0; T<=amount;T++){
            if(T%coins[0]==0) 
                prev[T]=T/coins[0];
            else prev[T] = 1e9;
        }

        for(int i=1;i<n;i++){
            for(int T=0;T<=amount;T++){
                int notTake = 0 + prev[T];
                int Take = INT_MAX;
                if(coins[i]<=T) Take = 1 + curr[T-coins[i]];
                curr[T] = min(Take, notTake);
            }
            prev = curr;
        }

        int ans = prev[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
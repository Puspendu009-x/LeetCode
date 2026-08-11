class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>after(5,0);
        vector<int>curr(5,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int t=3;t>=0;t--){
                if(t%2==0)
                curr[t]=max((-prices[ind]+after[t+1]),after[t]);
                else
                curr[t]=max((prices[ind]+after[t+1]),after[t]);
            }
            after = curr;
        }
        return after[0];
    }
};
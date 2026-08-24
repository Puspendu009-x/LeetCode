class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                int mini = INT_MAX;
                if(i>j) continue;
                for(int ind = i;ind<=j;ind++){
                    int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini = min(cost,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};
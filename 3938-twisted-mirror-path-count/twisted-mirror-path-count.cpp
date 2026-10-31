class Solution {
    #define ll long long
public:

    int mod=1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n,vector<ll>(2,0)));
        dp[0][0][0]=1;
        dp[0][0][1]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                for(int s=0;s<2;s++){
                if(grid[i][j]==1){
                if(s==0){
                    if(i>0)
                    dp[i][j][s]=dp[i-1][j][1];
                }
                else {
                    if(j>0)
                dp[i][j][s]=dp[i][j-1][0];
                }
                }
            else{
            ll up= (i>0)?dp[i-1][j][1]:0;
            ll left=(j>0)?dp[i][j-1][0]:0;
            dp[i][j][s]=(up+left)%mod;
            }
            }
            }
        }
        return dp[m-1][n-1][0];


    }
};
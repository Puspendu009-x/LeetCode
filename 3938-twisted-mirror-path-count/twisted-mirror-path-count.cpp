class Solution {
    #define ll long long
    private:
        int paths(int i,int j,int s,vector<vector<int>>& grid,vector<vector<vector<ll>>>&dp){
            if(i<0 || j<0) return 0;
            if(i==0 && j==0) return 1;

            if(dp[i][j][s]!=-1){
                return dp[i][j][s];
            }

            if(grid[i][j]==1){
                if(s==0) dp[i][j][s]=paths(i-1,j,1,grid,dp);
                else dp[i][j][s]= paths(i,j-1,0,grid,dp);
            }
            else{
            ll up=paths(i-1,j,1,grid,dp);
            ll left=paths(i,j-1,0,grid,dp);
            dp[i][j][s]=(up+left)%mod;
            }

            return dp[i][j][s];
        }
public:

    int mod=1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<ll>>>dp(m,vector<vector<ll>>(n,vector<ll>(2,-1)));
        ll ans=paths(m-1,n-1,0,grid,dp);
        return ans;
    }
};
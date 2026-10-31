class Solution {
    #define ll long long
public:
    int mod = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> dp(n, vector<ll>(2, 0));

        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                ll up = (i > 0) ? dp[j][1] : 0;
                ll left = (j > 0) ? dp[j-1][0] : 0;

                if (grid[i][j] == 1) {
                    dp[j][0] = up;
                    dp[j][1] = left;
                }
                else {
                    ll ways = (up + left) % mod;
                    dp[j][0] = ways;
                    dp[j][1] = ways;
                }
            }
        }

        return dp[n-1][0];
    }
};
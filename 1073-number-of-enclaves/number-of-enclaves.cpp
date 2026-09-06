class Solution {
    private:
        void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m){
            vis[row][col] = 1;
            int dRow[] ={-1,0,1,0};
            int dCol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row + dRow[i];
                int ncol = col +dCol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                dfs(nrow,ncol,vis,grid,n,m);
            }
        };
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1)
            dfs(0,i,vis,grid,n,m);
            if(!vis[n-1][i] && grid[n-1][i]==1)
            dfs(n-1,i,vis,grid,n,m);
        }
        for(int j=0;j<n;j++){
            if(!vis[j][0]&&grid[j][0]==1)
            dfs(j,0,vis,grid,n,m);
            if(!vis[j][m-1]&&grid[j][m-1]==1)
            dfs(j,m-1,vis,grid,n,m);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
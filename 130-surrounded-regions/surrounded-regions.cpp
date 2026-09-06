class Solution {
    private:
        void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m){
            vis[row][col]=1;
            int dRow[]={-1,0,1,0};
            int dCol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row+dRow[i];
                int ncol = col + dCol[i];
                if(ncol>=0&&ncol<m&&nrow>=0&&nrow<n&& vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board,n,m);
                }
            }
        };
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m =board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O')
            dfs(0,i,vis,board,n,m);
            if(!vis[n-1][i]&&board[n-1][i]=='O')
            dfs(n-1,i,vis,board,n,m);
        }

        for(int j=0;j<n;j++){
            if(!vis[j][0]&&board[j][0]=='O')
            dfs(j,0,vis,board,n,m);
            if(!vis[j][m-1]&&board[j][m-1]=='O')
            dfs(j,m-1,vis,board,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};
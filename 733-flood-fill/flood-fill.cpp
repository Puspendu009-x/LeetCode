class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        vector<vector<int>>ans = image;
        int dRow[] = {-1,0,+1,0};
        int dCol[] = {0,+1,0,-1};
        dfs(sr,sc,ans,image,color,ic,dRow,dCol);
        return ans;
    }

    void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int color,int ic,int dRow[],int dCol[]){
        ans[row][col] = color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ic && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,ans,image,color,ic,dRow,dCol);
            }
        }
    }
};
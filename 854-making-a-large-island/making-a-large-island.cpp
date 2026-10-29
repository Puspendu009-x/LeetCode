class DisjointSet{
    public:
        vector<int>size,parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }

        void UnionBySize(int u,int v){
            int ult_u=findUPar(u);
            int ult_v=findUPar(v);

            if(ult_u==ult_v) return;
            if(size[ult_u]<size[ult_v]){
                parent[ult_u]=ult_v;
                size[ult_v]+=size[ult_u];
            }
            else{
                parent[ult_v]=ult_u;
                size[ult_u]+=size[ult_v];
            }
        }
};


class Solution {

private:
    bool isValid(int nr,int nc,int n){
        return nr<n&&nr>=0&&nc<n&&nc>=0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;

                int dRow[]={-1,0,1,0};
                int dCol[]={0,1,0,-1};

                for(int i=0;i<4;i++){
                    int nrow=row+dRow[i];
                    int ncol=col+dCol[i];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                        int nodeNo=row*n+col;
                        int adjNodeNo=nrow*n+ncol;
                        ds.UnionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }

        int mx=0;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;

                int dRow[]={-1,0,1,0};
                int dCol[]={0,1,0,-1};

                set<int>components;

                for(int i=0;i<4;i++){
                    int nrow=row+dRow[i];
                    int ncol=col+dCol[i];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol]==1){
                            components.insert(ds.findUPar(nrow*n+ncol));
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }

                mx=max(mx,sizeTotal+1);

            }
        }

        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};
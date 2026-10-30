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
                size[ult_v]+=size[ult_u];
                parent[ult_u]=ult_v;
            } 
            else{
                size[ult_u]+=ult_v;
                parent[ult_v]=ult_u;
            }
        }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n=stones.size();
        int maxRow=0;
        int maxCol=0;

        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }

        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.UnionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }

        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first)
            cnt++;
        }

        return n-cnt;
    }
};
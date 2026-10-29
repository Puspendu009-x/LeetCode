class DisjointSet{
    public:
        vector<int>size,parent;
        DisjointSet(int n){
            size.resize(n+1,0);
            parent.resize(n+1,0);

            for(int i=0;i<=n;i++){
                size[i]=1;
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]) return node;
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }

        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntC++;
        }
        int ans=cntC-1;

        if(ans<=cntExtras) return ans;
        return -1;
    }
};
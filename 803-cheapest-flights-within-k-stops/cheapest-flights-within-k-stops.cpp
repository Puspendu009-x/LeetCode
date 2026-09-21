class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>>adj(n);

        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }


        queue<pair<int,pair<int,int>>>q;
        vector<int>cost(n);

        for(int i=0;i<n;i++) cost[i]=1e9;

        cost[src] = 0;

        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            if(stops>k)
                continue;

            for(auto iter:adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;

                if(price+edW < cost[adjNode] && stops<= k){
                    cost[adjNode] = price+edW;
                    q.push({stops+1,{adjNode,price + edW}});
                }
            }
        }
        if(cost[dst] != 1e9) return cost[dst];
        return -1;
    }
};
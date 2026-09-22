class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>>adj[n];
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n, 0);
        count[0] = 1;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            for(auto [adjnode, adjtime]: adj[node]){
                long long newtime = adjtime + time;
                if(dist[adjnode] == newtime){
                    count[adjnode] = (count[adjnode] + count[node]) % mod;
                }
                
                if(dist[adjnode] > newtime){
                    dist[adjnode] = newtime;
                    pq.push({newtime, adjnode});
                    count[adjnode] = count[node];
                }
            }
        }
        return count[n-1];
    }
};
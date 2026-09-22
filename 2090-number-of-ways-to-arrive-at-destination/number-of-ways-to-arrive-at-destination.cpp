class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> dist(n, 1e18);
        dist[0] = 0;

        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        pq.push({0, 0});
        int mod = 1e9 + 7;

        while (!pq.empty()) {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            if (dis > dist[node])
                continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                if (edW + dist[node] < dist[adjNode]) {
                    dist[adjNode] = edW + dist[node];
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }

                else if (edW + dist[node] == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
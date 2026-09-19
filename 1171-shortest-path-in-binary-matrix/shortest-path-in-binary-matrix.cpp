class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = 1;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return 1;
        map<pair<int, int>, int> mpp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    mpp[{i, j}] = k++;
            }
        }
        vector<vector<int>> adj(k);
        int dRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (auto it : mpp) {
            int node = it.second;
            for (int i = 0; i < 8; i++) {
                int nRow = it.first.first + dRow[i];
                int nCol = it.first.second + dCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 0) {
                    adj[node].push_back(mpp[{nRow, nCol}]);
                }
            }
        }
        queue<int> q;
        vector<int> dist(k);
        for (int i = 0; i < k; i++) {
            dist[i] = 1e9;
        }
        dist[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int node = q.front();

            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        if (dist[k - 1] == 1e9)
            return -1;
        return dist[k - 1];
    }
};
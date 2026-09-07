class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& check,
             vector<int>& pathvis, vector<vector<int>>& graph) {
        vis[node] = 1;
        check[node] = 0;
        pathvis[node] = 1;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, check, pathvis, graph))
                return true;
            }

            else {
                if (pathvis[it]) {
                    return true;
                }
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    };

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);
        vector<int> safenode;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i, vis, check, pathvis, graph);
        }

        for (int i = 0; i < n; i++) {
            if (check[i])
                safenode.push_back(i);
        }
        return safenode;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>gRev(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                gRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            q.push(i);
        }

        vector<int>safe_node;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe_node.push_back(node);

            for(auto it:gRev[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }

        sort(safe_node.begin(),safe_node.end());
        return safe_node;
    }
};
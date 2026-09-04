class Solution {
private:
    bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;

        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj)==true)
                return true;
            }
            else if(vis[it]==1)
            return true;
        }
        vis[node]=2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int>vis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj)==true) 
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&graph,vector<int>&safe){
        pathvis[i] = 1;
        vis[i] = 1;
        for(int j = 0; j < graph[i].size(); j++){
            if(!vis[graph[i][j]] && dfs(graph[i][j],vis,pathvis,graph,safe)){
                safe[graph[i][j]] = 0;
                return true;
            }
            else if(vis[graph[i][j]] && pathvis[graph[i][j]]){
                safe[graph[i][j]] = 0;
                return true;
            }
        }
        pathvis[i] = 0;
        safe[i] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0),pathvis(n,0),safe(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool ans = dfs(i,vis,pathvis,graph,safe);
            }
        }
        vector<int>res;
        for(int i = 0; i < n; i++){
            if(safe[i] == 1){
                res.push_back(i);
            }
        }
        return res;
    }
};
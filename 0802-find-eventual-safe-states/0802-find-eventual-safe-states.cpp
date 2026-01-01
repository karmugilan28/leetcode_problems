class Solution {
public: 
    bool dfs(int curr,vector<vector<int>>&graph,vector<int>&pathvis,vector<int>&vis,vector<int>&safe){
        pathvis[curr] = 1;
        vis[curr] = 1;
        for(auto&it:graph[curr]){
            if((vis[it] == 1 && pathvis[it] == 1)){
                safe[it] = 0;
                return true;
            }
            else if(!vis[it] && dfs(it,graph,pathvis,vis,safe)){
                safe[it] = 0;
                return true;
            }
        }
        pathvis[curr] = 0;
        safe[curr] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>res;
        vector<int>vis(n,0),pathvis(n,0),safe(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool ans = dfs(i,graph,pathvis,vis,safe);
            }
            if(safe[i]) res.push_back(i);
        }
        return res;
    }
};
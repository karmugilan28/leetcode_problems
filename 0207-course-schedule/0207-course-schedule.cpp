class Solution {
public:
    bool dfs(int i,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj){
        vis[i] = 1;
        pathvis[i] = 1;
        for(int j = 0; j < adj[i].size(); j++){
            if(!vis[adj[i][j]] && dfs(adj[i][j],vis,pathvis,adj) == true)  return true;
            else if(pathvis[adj[i][j]] && vis[adj[i][j]])   return true;
        }
        pathvis[i] = 0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                int a = adj[i][j];
                for(int k = 0; k < adj[a].size(); k++){
                    if(adj[a][k] == i)  return false;
                }
            }
        }
        vector<int>vis(n,0),pathvis(n,0);
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj))  return false;
            }
        }
        return true;
    }
};
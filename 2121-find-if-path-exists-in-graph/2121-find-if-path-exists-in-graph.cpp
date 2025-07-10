class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        vector<bool>vis(n,false);
        int st = source;
        q.push(st);
        vis[st] = 1;
        while(!q.empty()){
            int a = q.front();
            for(int i = 0; i < adj[a].size(); i++){
                if(!vis[adj[a][i]]){
                    if(adj[a][i] == destination)    return true;
                    vis[adj[a][i]] = true;
                    q.push(adj[a][i]);
                }
            }
            q.pop();
        }
        for(int i = 0; i < vis.size(); i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
};
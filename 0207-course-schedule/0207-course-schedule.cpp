class Solution {
    //dfs to detect cycle in a graph
// public:
//     bool dfs(int i,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj){
//         vis[i] = 1;
//         pathvis[i] = 1;
//         for(int j = 0; j < adj[i].size(); j++){
//             if(!vis[adj[i][j]] && dfs(adj[i][j],vis,pathvis,adj) == true)  return true;
//             else if(pathvis[adj[i][j]] && vis[adj[i][j]])   return true;
//         }
//         pathvis[i] = 0;
//         return false;
//     }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        //just detect there si cycle and whether there is bidirected edge between any two nodes
        // for(int i = 0; i < edges.size(); i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        // }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < adj[i].size(); j++){
        //         int a = adj[i][j];
        //         for(int k = 0; k < adj[a].size(); k++){
        //             if(adj[a][k] == i)  return false;
        //         }
        //     }
        // }
        // vector<int>vis(n,0),pathvis(n,0);
        // for(int i = 0 ; i < n; i++){
        //     if(!vis[i]){
        //         if(dfs(i,vis,pathvis,adj))  return false;
        //     }
        // }
        // return true;
        //usi9ng topo sort loghic using bfs simple to implement
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>indegree(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)    q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int curr = q.front();
            topo.push_back(curr);
            for(auto& it:adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0)   q.push(it);
            }
            q.pop();
        }
        if(topo.size() == n)    return true;
        else    return false;
    }
};
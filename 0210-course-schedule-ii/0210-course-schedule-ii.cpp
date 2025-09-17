class Solution {
// used this dfs to detect cycle in a grah
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
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //bfs topo sort
        // the below is to check nwhther there is bidirected edge in a graph
        // because if topo sort is possible only in directed acyclic graph
        // int flg = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < adj[i].size(); j++){
        //         int a = adj[i][j];
        //         for(int k = 0; k < adj[a].size(); k++){
        //             if(adj[a][k] == i){
        //                 flg = 1;
        //                 break;
        //             }
        //         }
        //         if(flg == 1)    break;
        //     }
        //     if(flg == 1)    break;
        // }
        // if(flg == 1)    return {};

        // to detect cycle
        // vector<int>vis(n,0),pathvis(n,0);
        // for(int i = 0 ; i < n; i++){
        //     if(!vis[i]){
        //         if(dfs(i,vis,pathvis,adj)){
        //             flg = 1;
        //             break;
        //         }
        //     }
        // }
        // if(flg == 1)    return {};
        // we can exclude the above code by doing small change
        vector<int>deg(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                deg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(deg[i] == 0) q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int curr = q.front();
            res.push_back(curr);
            for(int i = 0; i < adj[curr].size(); i++){
                deg[adj[curr][i]]--;
                if(deg[adj[curr][i]] == 0)   q.push(adj[curr][i]);
            }
            q.pop();
        }
        //thyis below condition checks wthere there is a cycle or bidirected edge in a graph
        // when we create a linear ordering there should be exactly n elements in a res vector
        // otherwise there ia cycle formed in a graph
        if(res.size() < n)  return {};
        return res;
    }
};
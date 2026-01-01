class Solution {
// public: 
//     bool dfs(int curr,vector<vector<int>>&graph,vector<int>&pathvis,vector<int>&vis,vector<int>&safe){
//         pathvis[curr] = 1;
//         vis[curr] = 1;
//         for(auto&it:graph[curr]){
//             if((vis[it] == 1 && pathvis[it] == 1)){
//                 safe[it] = 0;
//                 return true;
//             }
//             else if(!vis[it] && dfs(it,graph,pathvis,vis,safe)){
//                 safe[it] = 0;
//                 return true;
//             }
//         }
//         pathvis[curr] = 0;
//         safe[curr] = 1;
//         return false;
//     }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<int>res;
        // vector<int>vis(n,0),pathvis(n,0),safe(n,0);
        // for(int i = 0; i < n; i++){
        //     if(!vis[i]){
        //         bool ans = dfs(i,graph,pathvis,vis,safe);
        //     }
        //     if(safe[i]) res.push_back(i);
        // }
        // return res;

        // bfs kahn's algorithm
        //change the problem slight that reverse the edges because the terminal node has out degree 0
        // we can't do anything with out degree related topo sort. so we change the edge to opposite so that the out degree becomes in degree and apply topo sort as always
        vector<vector<int>>adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++)
                adj[graph[i][j]].push_back(i);
        }
        // for(int i = 0; i < adj.size(); i++){
        //     for(int j = 0; j < adj[i].size(); j++)  cout << adj[i][j] << " ";
        //     cout << endl;
        // }
        queue<int>q;
        vector<int>indeg(n,0),res;
        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[i].size(); j++)
                indeg[adj[i][j]]++;
        }
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            for(auto&it:adj[curr]){
                indeg[it] -= 1;
                if(indeg[it] == 0){
                    q.push(it);
                    res.push_back(it);
                }
            }
            q.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
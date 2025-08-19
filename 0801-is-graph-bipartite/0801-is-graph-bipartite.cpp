class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        queue<int>q;
        
        for(int g = 0; g < n; g++){
            if(vis[g] == -1){
                vis[g] = 0;
                q.push(g);
                while(!q.empty()){
                    int a = q.front();
                    for(int i = 0; i < graph[a].size(); i++){
                        if(vis[graph[a][i]] == -1){
                            if(vis[a] == 0)    vis[graph[a][i]] = 1;
                            else    vis[graph[a][i]] = 0;
                            q.push(graph[a][i]);
                        }
                        else if(vis[a] == vis[graph[a][i]]) return false;
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};
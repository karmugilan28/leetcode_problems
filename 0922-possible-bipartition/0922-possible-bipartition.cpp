class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& grid) {
        int m = grid.size();
        vector<vector<int>>adj(n+1);
        vector<int>vis(n+1,-1);
        for(int i = 0; i < m; i++){
            adj[grid[i][0]].push_back(grid[i][1]);
            adj[grid[i][1]].push_back(grid[i][0]);
        }
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j < adj[i].size(); j++){
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        queue<int>q;
        for(int i = 1; i <= n; i++){
            if(vis[i] == -1){
                q.push(i);
                vis[i] = 0;
                while(!q.empty()){
                    int a = q.front();
                    for(int j = 0; j < adj[a].size(); j++){
                        if(vis[adj[a][j]] == -1){
                            if(vis[a] == 0) vis[adj[a][j]] = 1;
                            else    vis[adj[a][j]] = 0;
                            q.push(adj[a][j]);
                        }
                        else if(vis[a] == vis[adj[a][j]])  return false;
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};
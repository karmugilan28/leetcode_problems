class Solution {
// public:
//     int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,queue<pair<pair<int,int>,int>>&q){
//         if(q.empty())   return 0;
//         pair<pair<int,int>,int> curr = q.front();
//         int a = curr.first.first, b = curr.first.second, c = curr.second;
//         if(grid[a][b] == 0){
//             return c;
//         }
//         for(int k = -1; k <= 1; k += 2){
//             if(a+k >= 0 && a+k < grid.size() && !vis[k+a][b]){
//                 q.push({{a+k,b},c+1});
//                 vis[a+k][b] = 1;
//             }
//             if(b+k >= 0 && b+k < grid[0].size() && !vis[a][b+k]){
//                 q.push({{a,b+k},c+1});
//                 vis[a][b+k] = 1;
//             }
//         }
//         q.pop();
//         return bfs(grid,vis,q);
//     }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0)),vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            int a = curr.first.first, b = curr.first.second, c = curr.second;
            for(int k = -1; k <= 1; k += 2){
                if(a+k >= 0 && a+k < n && !vis[k+a][b]){
                    q.push({{a+k,b},c+1});
                    vis[a+k][b] = 1;
                }
                if(b+k >= 0 && b+k < m && !vis[a][b+k]){
                    q.push({{a,b+k},c+1});
                    vis[a][b+k] = 1;
                }
            }
            res[a][b] = c;
            q.pop();
        }
        return res;
        // vector<vector<int>>res(n,vector<int>(m,0)),vis(n,vector<int>(m,0));

    }
};
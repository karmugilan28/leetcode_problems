class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n = grid.size(),m = grid[0].size();
        int st = grid[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        grid[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        while(!q.empty()){
            pair<int,int> curr = q.front();
            int a = curr.first, b = curr.second;
            for(int i = -1; i <= 1; i++){
                if(i != 0){
                    if((i+a >= 0 && i+a < n) && grid[a+i][b] == st && !vis[i+a][b]){
                        grid[a+i][b] = color;
                        vis[i+a][b] = 1;
                        q.push({i+a,b});
                    }
                    if((i+b >= 0 && i+b < m) && grid[a][b+i] == st && !vis[a][b+i]){
                        grid[a][b+i] = color;
                        vis[a][b+i] = 1;
                        q.push({a,b+i});
                    }
                }
            }
            q.pop();
        }
        return grid;
    }
};
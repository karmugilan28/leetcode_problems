class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 'O'){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            pair<int,int> curr = q.front();
            int a = curr.first, b = curr.second;
            for(int i = -1; i <= 1; i+=2){
                if(a+i >= 0 && a+i < n && !vis[a+i][b] && grid[a+i][b] == 'O'){
                    vis[a+i][b] = 1;
                    q.push({a+i,b});
                }
                if(b+i >= 0 && b+i < m && !vis[a][b+i] && grid[a][b+i] == 'O'){
                    vis[a][b+i] = 1;
                    q.push({a,b+i});
                }
            }
            q.pop();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j])  grid[i][j] = 'X';
            }
        }
        return ;
    }
};
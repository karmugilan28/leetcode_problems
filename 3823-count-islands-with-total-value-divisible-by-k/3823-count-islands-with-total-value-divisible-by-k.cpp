class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int ct = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                long long sum = 0;
                if(grid[i][j] > 0 && !vis[i][j]){
                    int st = grid[i][j];
                    vis[i][j] = 1;
                    sum += st;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int,int> curr = q.front();
                        int a = curr.first, b = curr.second;
                        for(int g = -1; g <= 1; g++){
                            if(g != 0){
                                if((a+g >= 0 && a+g < n) && !vis[a+g][b] && grid[a+g][b] > 0){
                                    q.push({a+g,b});
                                    sum += grid[a+g][b];
                                    vis[a+g][b] = 1;
                                }
                                if((b+g >= 0 && b+g < m) && !vis[a][b+g] && grid[a][b+g] > 0){
                                    q.push({a,b+g});
                                    sum += grid[a][b+g];
                                    vis[a][b+g] = 1;
                                }
                            }
                        }
                        q.pop();
                    }
                    if(sum % k == 0 && sum != 0){
                        ct++;
                    }
                }
               
            }
            
        }
        return ct;
    }
};
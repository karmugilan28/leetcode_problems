class Solution {
public:
    int numIslands(vector<vector<char>>& gr) {
        int n = gr.size(), m = gr[0].size();
        vector<vector<char>>grid(n+2,vector<char>(m+2,'0'));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                grid[i][j] = gr[i-1][j-1];
            }
        }
        vector<vector<int>>vis(n+2,vector<int>(m+2,0));
        queue<pair<int,int>>q;
        int ct = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        pair<int,int>curr = q.front();
                        int a = curr.first, b =curr.second;
                        if(grid[a+1][b] =='1' && vis[a+1][b] == 0)  {q.push({a+1,b}); vis[a+1][b] = 1;}
                        if(grid[a][b+1] == '1' && vis[a][b+1] == 0) {q.push({a,b+1}); vis[a][b+1] = 1;}
                        if(grid[a-1][b] == '1' && vis[a-1][b] == 0) {q.push({a-1,b}); vis[a-1][b] = 1;}
                        if(grid[a][b-1] == '1' && vis[a][b-1] == 0) {q.push({a,b-1}); vis[a][b-1] = 1;} 
                        q.pop();
                    }
                    ct++;
                }
            }
        }
        return ct;
    }
};
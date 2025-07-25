class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         int ct = 0;
        //         if(grid[i][j] == 2 && !vis[i][j]){
        //             queue<pair<int,int>>q;
        //             vis[i][j] = 1;
        //             q.push({i,j});
        //             while(!q.empty()){
        //                 pair<int,int> a = q.front();
        //                 int c = a.first, d = a.second;
        //                 int flg = 0;
        //                 for(int g = -1; g <= 1 ; g+=2){
        //                     if((d+g >= 0 && d+g < m) && grid[c][d+g] == 1 && !vis[c][d+g]){
        //                         vis[c][d+g] = 1;
        //                         flg = 1;
        //                         q.push({c,d+g});
        //                     }
        //                     if((c+g >= 0 && c+g < n) && grid[c+g][d] == 1 && !vis[c+g][d]){
        //                         vis[c+g][d] = 1;
        //                         flg = 1;
        //                         q.push({c+g,d});
        //                     }
        //                 }
        //                 if(flg == 1)    ct++;
        //                 q.pop();
        //             }
        //         }
        //         maxi = max(maxi,ct);
        //     }
        // }

        //since we require the minimum time that all oranges rotten, basically we need the level of each rotten orange and iterate it
        // so we use the pair<pair<int,int>,int> which store{i,j,min_time to rotten i,j}
        // byapply bfs n this we willl get correct answer
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            pair<pair<int,int>,int> curr = q.front();
            int a = curr.first.first, b = curr.first.second, c = curr.second;
            for(int i = -1; i <= 1; i += 2){
                if(a+i >= 0 && a+i < n && !vis[a+i][b] && grid[a+i][b] == 1){
                    vis[a+i][b] = 1;
                    q.push({{a+i,b},c+1}); //here we update the mintime to prev_mintime of the previous node +1 due to
                }
                if(b+i >= 0 && b+i < m && !vis[a][b+i] && grid[a][b+i] == 1){
                    vis[a][b+i] = 1;
                    q.push({{a,b+i},c+1});
                }
            }
            ans = c;
            q.pop();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)  if(grid[i][j] == 1 && vis[i][j] == 0)   return -1;
        }
        return ans;
    }
};
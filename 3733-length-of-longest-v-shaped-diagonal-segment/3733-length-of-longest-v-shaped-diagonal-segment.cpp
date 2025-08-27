class Solution {
public:
    int fn(int i, int j,int cnt,int prev,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp,int n,int m){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)   return 0;
        if(dp[i][j][cnt][prev] != -1)   return dp[i][j][cnt][prev];
        if(grid[i][j] == 0){
            if(cnt == 1){
                int a = 0, b  = 0, c = 0 ,d = 0;
                if(prev == 0 && i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2)    a = 1 + fn(i+1,j-1,cnt,0,grid,dp,n,m);
                else if(prev == 1 && i+1 < n && j+1 < m && grid[i+1][j+1] == 2)  b = 1 + fn(i+1,j+1,cnt,1,grid,dp,n,m);
                else if(prev == 2 && i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2)  c = 1 + fn(i-1,j+1,cnt,2,grid,dp,n,m);
                else if(prev == 3 && i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2)    d = 1 + fn(i-1,j-1,cnt,3,grid,dp,n,m);
                return dp[i][j][cnt][prev] = max(a,max(b,max(c,d)));
            }
            else if(cnt < 1){
                int a = 0,d = 0,b = 0,c = 0;
                if(prev == 0){
                    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2)  a = 1 + fn(i+1,j-1,cnt,prev,grid,dp,n,m);
                    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2) d = 1 + fn(i-1,j-1,cnt+1,3,grid,dp,n,m);
                }
                else if(prev == 1){
                    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2)  b = 1 + fn(i+1,j+1,cnt,prev,grid,dp,n,m);
                    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2)  a = 1 + fn(i+1,j-1,cnt+1,0,grid,dp,n,m);
                }
                else if(prev == 2){
                    if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2)  c = 1 + fn(i-1,j+1,cnt,prev,grid,dp,n,m);
                    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2)   b = 1 + fn(i+1,j+1,cnt+1,1,grid,dp,n,m);
                }
                else{
                    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2) d = 1 + fn(i-1,j-1,cnt,prev,grid,dp,n,m);
                    if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2)   c = 1 + fn(i-1,j+1,cnt+1,2,grid,dp,n,m);
                }
                return dp[i][j][cnt][prev] = max({a,b,c,d});
            }
            else    return dp[i][j][cnt][prev] = 0;
        }
        else if(grid[i][j] == 2){
            if(cnt == 1){
                int a = 0, b  = 0, c = 0 ,d = 0;
                if(prev == 0 && i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0)    a = 1 + fn(i+1,j-1,cnt,0,grid,dp,n,m);
                else if(prev == 1 && i+1 < n && j+1 < m && grid[i+1][j+1] == 0)  b = 1 + fn(i+1,j+1,cnt,1,grid,dp,n,m);
                else if(prev == 2 && i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 0)  c = 1 + fn(i-1,j+1,cnt,2,grid,dp,n,m);
                else if(prev == 3 && i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0)    d = 1 + fn(i-1,j-1,cnt,3,grid,dp,n,m);
                return dp[i][j][cnt][prev] = max(a,max(b,max(c,d)));
            }
            else if(cnt < 1){
                int a = 0,d = 0,b = 0,c = 0;
                if(prev == 0){
                    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0)  a = 1 + fn(i+1,j-1,cnt,prev,grid,dp,n,m);
                    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0) d = 1 + fn(i-1,j-1,cnt+1,3,grid,dp,n,m);
                }
                else if(prev == 1){
                    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 0)  b = 1 + fn(i+1,j+1,cnt,prev,grid,dp,n,m);
                    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0)  a = 1 + fn(i+1,j-1,cnt+1,0,grid,dp,n,m);
                }
                else if(prev == 2){
                    if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 0)  c = 1 + fn(i-1,j+1,cnt,prev,grid,dp,n,m);
                    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 0)   b = 1 + fn(i+1,j+1,cnt+1,1,grid,dp,n,m);
                }
                else{
                    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0) d = 1 + fn(i-1,j-1,cnt,prev,grid,dp,n,m);
                    if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 0)   c = 1 + fn(i-1,j+1,cnt+1,2,grid,dp,n,m);
                }
                return dp[i][j][cnt][prev] = max({a,b,c,d});
            }
            else    return dp[i][j][cnt][prev] = 0;
        }
        else    return dp[i][j][cnt][prev] = 0;  
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxi = 0;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(2,vector<int>(4,-1))));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int a = 0,b = 0, c = 0, d = 0;
                    if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2) a = 1+fn(i+1,j-1,0,0,grid,dp,n,m);
                    if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2) b = 1+fn(i+1,j+1,0,1,grid,dp,n,m);
                    if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2) c = 1+fn(i-1,j+1,0,2,grid,dp,n,m);
                    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2) d = 1+fn(i-1,j-1,0,3,grid,dp,n,m);
                    maxi = max(maxi,1+max(a,max(b,max(c,d))));
                }
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int fn(int i,int j,int x,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i == 0 && j == 0){
            dp[i][j][x^grid[i][j]] = 1;
            return 1;
        };
        if(i < 0 || j < 0)  return 1e9;
        if(dp[i][j][x] != -1)  return dp[i][j][x];
        int r = fn(i,j-1,x^grid[i][j],grid,dp);
        int d = fn(i-1,j,grid[i][j]^x,grid,dp);
        return dp[i][j][x] = r || d;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        int a = fn(m-1,n-1,0,grid,dp);
        // for()
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         for(int x = 0; x <= 1024; x++){

        //         }
        //     }
        // }
        for(int i = 0; i <= 1023; i++){
            if(dp[0][0][i] == 1)    return i;
        }
        return -1;
    }
};
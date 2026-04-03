class Solution {
public:
    int fn(int i,int j,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(i >= grid.size() || j >= grid[0].size()) return -1e9;
        if(dp[i][j][k] != -1)   return dp[i][j][k];
        if(i == grid.size()-1 && j == grid[0].size()-1){
            if(grid[i][j] < 0){
                if(k > 0)   return dp[i][j][k] = 0;
            }
            return dp[i][j][k] = grid[i][j];
        }
        if(grid[i][j] < 0){
            int rob = -1e9;
            int r = -1e9, d = -1e9;
            if(k > 0)    rob = max(fn(i+1,j,k-1,grid,dp),fn(i,j+1,k-1,grid,dp));
            r = grid[i][j] + fn(i+1,j,k,grid,dp);
            d = grid[i][j] + fn(i,j+1,k,grid,dp);
            return dp[i][j][k] = max({rob,r,d});
        }
        else{
            int r = grid[i][j] + fn(i,j+1,k,grid,dp); 
            int d = grid[i][j] + fn(i+1,j,k,grid,dp);
            return dp[i][j][k] = max({r,d});
        }
    }
public:
    int maximumAmount(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,0)));
        for(int g = 0; g < 3; g++){
            if(grid[m-1][n-1] < 0){
                if(g > 0)   dp[m-1][n-1][g] = 0;
                else    dp[m-1][n-1][g] = grid[m-1][n-1];
            }
            else    dp[m-1][n-1][g] = grid[m-1][n-1];
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1)    continue;
                for(int k = 0; k < 3; k++){
                    if(grid[i][j] < 0){
                        int rob = -1e9;
                        int r = -1e9, d = -1e9;
                        if(k > 0){
                            int o = -1e9, p = -1e9;
                            if(i < m-1) o = dp[i+1][j][k-1];
                            if(j < n-1) p = dp[i][j+1][k-1];
                            rob = max(o,p);
                        }
                        int o = -1e9, p = -1e9;
                        if(i < m-1) o = dp[i+1][j][k];
                        if(j < n-1) p = dp[i][j+1][k];
                        r = grid[i][j] + o;
                        d = grid[i][j] + p;
                        dp[i][j][k] = max({rob,r,d});
                    }
                    else{
                        int o = -1e9, p = -1e9;
                        if(i < m-1) o = dp[i+1][j][k];
                        if(j < n-1) p = dp[i][j+1][k];
                        int r = grid[i][j] + o;
                        int d = grid[i][j] + p;
                        dp[i][j][k] = max({r,d});
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};
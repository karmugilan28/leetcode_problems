class Solution {
public:
    int c1(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == grid.size()-1 && j == grid.size()-1)    return 0;
        if(i == grid.size()-1)  return -1e9;
        if((j <= i || j > grid.size()-1))  return -1e9;
        if(dp[i][j] != -1)   return dp[i][j];
        int leftd = grid[i][j] + c1(i+1,j-1,grid,dp);
        int down = grid[i][j] + c1(i+1,j,grid,dp);
        int rightd = grid[i][j] + c1(i+1,j+1,grid,dp);
        return dp[i][j] = max(leftd,max(down,rightd));
    }
public:
    int c2(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i == grid.size()-1 && j == grid.size()-1)    return 0;
        if(j == grid.size()-1)  return -1e9;
        if((j >= i || i > grid.size()-1))  return -1e9;
        if(dp[i][j] != -1)   return dp[i][j];
        int leftd = grid[i][j] + c2(i-1,j+1,grid,dp);
        int right = grid[i][j] + c2(i,j+1,grid,dp);
        int rightd = grid[i][j] + c2(i+1,j+1,grid,dp);
        return dp[i][j] = max(leftd,max(right,rightd));
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int sum = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    sum += fruits[i][j];
                    fruits[i][j] = -1;
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int d = c1(0,n-1,fruits,dp);
        int e = c2(n-1,0,fruits,dp);
        sum += (d+e);
        return sum;
    }
};
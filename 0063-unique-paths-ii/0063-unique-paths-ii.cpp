class Solution {
//memoization
// public:
    // int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(i==0 && j==0)
    //         return 1;
    //     if(i<0 || j<0)
    //         return 0;
    //     int l=0,r=0;
    //     if(i>0 && grid[i-1][j]==0)
    //         l=fn(i-1,j,grid,dp);
    //     if(j>0 && grid[i][j-1]==0)
    //         r=fn(i,j-1,grid,dp);
    //     return dp[i][j]=l+r;
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        //memoization
        // if(obstacleGrid[m-1][n-1]==1)
        //     return 0;

        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=fn(m-1,n-1,obstacleGrid,dp);
        // return ans;

        //tabulation
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0])
            return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    dp[i][j]=1;
                else{
                    int l=0,r=0;
                    if(i>0 && obstacleGrid[i][j]==0)
                        l=dp[i-1][j];
                    if(j>0 && obstacleGrid[i][j]==0)
                        r=dp[i][j-1];
                    dp[i][j]=l+r;
                }             
            }
        }
        return dp[m-1][n-1];
    }
};
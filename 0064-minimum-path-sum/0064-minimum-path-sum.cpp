class Solution {
//memoization
// public:
//     int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
//         if(i==0 && j==0){
//             return grid[i][j];
//         }
//         if(i<0 || j<0)
//             return 9999999;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int l=0,r=0;
//         l=grid[i][j]+fn(i-1,j,grid,dp);
//         r=grid[i][j]+fn(i,j-1,grid,dp);
//         return  dp[i][j]=min(l,r);
//     }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //memoization
        //int m=grid.size(),n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=fn(m-1,n-1,grid,dp);
        // return ans;

        //tabulation
        // int m=grid.size(),n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,0));         
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)
        //             dp[i][j]=grid[i][j];
        //         else{
        //             int l=INT_MAX,r=INT_MAX;
        //             if(i>0)
        //                 l=grid[i][j]+dp[i-1][j];
        //             if(j>0)
        //                 r=grid[i][j]+dp[i][j-1];
        //             dp[i][j]=min(l,r);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        //space optimization
        //I want space optimize from space of O(m*n) to O(n);
        int m=grid.size(),n=grid[0].size();
        vector<int>dp(n,0);
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=grid[0][j];
            dp[j]=sum;
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                    dp[j]=grid[i][j]+dp[j];
                else{
                    int l=grid[i][j]+dp[j-1];
                    int r=grid[i][j]+dp[j];
                    dp[j]=min(l,r);
                }
            }
        }
        return dp[n-1];
    }
};
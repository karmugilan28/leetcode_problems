class Solution {
//memoization
// public:
//     int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){  
//         if(j<0 || j>grid.size()-1)
//             return 99999;
//         if(dp[i][j]!=-1000)
//             return dp[i][j];
//         if(i==0 && j>=0)
//             return grid[i][j];
//         int l=INT_MAX,r=INT_MAX,g=INT_MAX,maxi=999999;
//         if(i==grid.size()-1){
//             for(int k=grid.size()-1;k>=0;k--){
//                 l=grid[i][k]+fn(i-1,k,grid,dp);
//                 r=grid[i][k]+fn(i-1,k-1,grid,dp);
//                 g=grid[i][k]+fn(i-1,k+1,grid,dp);
//                 maxi=min(maxi,min(l,min(r,g)));
//             }
//         }
//         else{
//             l=grid[i][j]+fn(i-1,j,grid,dp);
//             r=grid[i][j]+fn(i-1,j-1,grid,dp);
//             g=grid[i][j]+fn(i-1,j+1,grid,dp);
//         }
//         maxi=min(maxi,min(l,min(r,g)));
//         return dp[i][j]=maxi;
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //memoization
        // int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1000));
        // return fn(n-1,n-1,matrix,dp);

        //tabulation
        // int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0)
        //             dp[i][j]=matrix[i][j];
        //         else{
        //             int l=INT_MAX,r=INT_MAX,g=INT_MAX;
        //             if(j==0){
        //                 l=matrix[i][j]+dp[i-1][j];
        //                 r=matrix[i][j]+dp[i-1][j+1];
        //             }
        //             else if(j==n-1){
        //                 g=matrix[i][j]+dp[i-1][j-1];
        //                 l=matrix[i][j]+dp[i-1][j];
        //             }
        //             else{
        //                 l=matrix[i][j]+dp[i-1][j];
        //                 r=matrix[i][j]+dp[i-1][j+1];
        //                 g=matrix[i][j]+dp[i-1][j-1];
        //             }
        //             dp[i][j]=min(l,min(r,g));
        //         }
        //     }
        // }
        // int mini=INT_MAX;
        // for(int j=0;j<n;j++){
        //     if(dp[n-1][j]<mini)
        //         mini=dp[n-1][j];
        // }
        // return mini;

        //space optimization
        int n=matrix.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            vector<int>nums(n);
            for(int j=0;j<n;j++){
                int l=INT_MAX,r=INT_MAX,g=INT_MAX;
                if(i==0)
                    nums[j]=matrix[i][j];
                else{
                    if(j==0){
                        l=matrix[i][j]+dp[j];
                        r=matrix[i][j]+dp[j+1];
                    }
                    else if(j==n-1){
                        g=matrix[i][j]+dp[j-1];
                        l=matrix[i][j]+dp[j];
                    }
                    else{
                        l=matrix[i][j]+dp[j];
                        r=matrix[i][j]+dp[j+1];
                        g=matrix[i][j]+dp[j-1];
                    }
                    nums[j]=min(l,min(r,g));
                }
            }
            dp=nums;
        }
        int c=*min_element(dp.begin(),dp.end());
        return c;
    }
};
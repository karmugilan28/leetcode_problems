class Solution {
//memoization with time complexity of O(n^2) and space complexity of O(n^2)+O(n)
// public:
//     int fn(int i,int j,vector<vector<int>>&grid,int last,vector<vector<int>>&dp){
//         if(i==0){
//             int m=INT_MAX;
//             for(int g=grid.size()-1;g>=0;g--){
//                 if(last!=g)
//                     m=min(m,grid[i][g]);
//             }
//             return m;
//         }
//         if(dp[i][j]!=-100)
//             return dp[i][j];
//         int mini=INT_MAX,l=INT_MAX;
//         for(int k=grid.size()-1;k>=0;k--){
//             if(k!=last){
//                 l=grid[i][k]+fn(i-1,k,grid,k,dp);
//                 mini=min(l,mini);
//             }
//         }
//         return dp[i][j]=mini;
//     }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        //memoization
        // int n=grid.size();
        // vector<vector<int>>dp(n,vector<int>(n,-100));
        // int minii=INT_MAX;
        // for(int j=n-1;j>=0;j--){
        //     int ans=fn(n-1,j,grid,-1,dp);
        //     minii=min(minii,ans);
        // }
        // return minii;


        //tabulation
        // int n=grid.size();
        // vector<vector<int>>dp(n,vector<int>(n,-100));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0)
        //             dp[i][j]=grid[i][j];
        //         else{
        //             int mini=INT_MAX,l=INT_MAX;
        //             for(int k=0;k<n;k++){
        //                 if(k!=j){
        //                    l=grid[i][j]+dp[i-1][k];
        //                    mini=min(l,mini);
        //                 }
        //             }
        //             dp[i][j]=mini;
        //         }
        //     }
        // }
        // int minii=INT_MAX;
        // for(int i=0;i<n;i++)
        //     minii=min(minii,dp[n-1][i]);
        // return minii;

        //space optimization:
        int n=grid.size();
        vector<int>dp(n,0);
        for(int j=0;j<n;j++)
            dp[j]=grid[0][j];
        for(int i=1;i<n;i++){
            vector<int>nums(n,0);
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j)
                        mini=min(mini,grid[i][j]+dp[k]);
                }
                nums[j]=mini;
            }
            dp=nums;
        }
        int minii=INT_MAX;
        for(int i=0;i<n;i++)
            minii=min(minii,dp[i]);
        return minii;
    }
};
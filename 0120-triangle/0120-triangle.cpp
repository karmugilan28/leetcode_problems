class Solution {
//memoization
// public:
//     int fn(int i,int j,vector<vector<int>>&grid,int m,vector<vector<int>>& dp){
//         if(i!=0)
//             if(i>m || j>grid[i-1].size())   return 0;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int l=grid[i][j]+fn(i+1,j,grid,m,dp);
//         int r=grid[i][j]+fn(i+1,j+1,grid,m,dp);
//         return dp[i][j]=min(l,r);
//     }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //memoization
        // vector<vector<int>>dp;
        // int m=triangle.size();
        // for(int i=0;i<m;i++){
        //     vector<int>nums;
        //     for(int j=0;j<triangle[i].size();j++){
        //         nums.push_back(-1);
        //     }
        //     dp.push_back(nums);
        // }
        // int n=m;
        // int ans=fn(0,0,triangle,m-1,dp);
        // return ans;

        //tabulation with time complexity of 
        // int m=triangle.size();
        // vector<vector<int>>dp;
        // for(int i=0;i<m;i++){
        //     vector<int>nums;
        //     for(int j=0;j<triangle[i].size();j++){
        //         nums.push_back(0);
        //     }
        //     dp.push_back(nums);
        // }
        // for(int i=m-1;i>=0;i--){
        //     for(int j=triangle[i].size()-1;j>=0;j--){
        //         if(i==m-1)
        //             dp[i][j]=triangle[i][j];
        //         else{
        //             int l=triangle[i][j]+dp[i+1][j];
        //             int r=triangle[i][j]+dp[i+1][j+1];
        //             dp[i][j]=min(l,r);
        //         }
        //     }
        // }
        // return dp[0][0];

        //space optimization
        int n  = triangle.size();
        vector<vector<int>>dp;
        for(int i = 0; i < n; i++){
            vector<int>a;
            for(int j = 0; j < i+1; j++)    a.push_back(0);
            dp.push_back(a);
        }
        for(int i = 0; i < n; i++)    dp[n-1][i] = triangle[n-1][i];
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                int d = triangle[i][j] + dp[i+1][j+1];
                int e = triangle[i][j] + dp[i+1][j];
                dp[i][j] = min(d,e);
            }
        }
        return dp[0][0];
    }
};
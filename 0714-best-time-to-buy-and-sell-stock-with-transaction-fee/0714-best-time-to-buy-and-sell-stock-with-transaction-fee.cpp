class Solution {
//tabulation
// public:
//     int fn(int i,int op,int fee,vector<int>&nums,vector<vector<int>>&dp){
//         if(i == 0){
//             if(op == 1) return -nums[i];
//             return 0;
//         }
//         if(dp[i][op] != -1) return dp[i][op];
//         int notdo = fn(i-1,op,fee,nums,dp);
//         if(op == 0) return dp[i][op] = max(notdo,nums[i]-fee + fn(i-1,1,fee,nums,dp));
//         return dp[i][op] = max(notdo,-nums[i] + fn(i-1,0,fee,nums,dp));
//     }
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n = nums.size();
        //memoization
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return fn(n-1,0,fee,nums,dp);

        //tabulation
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][1] = -nums[0], dp[0][0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 2; j++){
                int notdo = dp[i-1][j];
                if(j == 0) dp[i][j] = max(notdo,nums[i]-fee + dp[i-1][1]);
                else    dp[i][j] = max(notdo,-nums[i] + dp[i-1][0]);
            }
        }
        return dp[n-1][0];

        //spce optimization
        // vector<int>prev(n,0),curr(n,0);
        // if(n < 2)   return 0;
        // prev[1] = -nums[0], prev[0] = 0;
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < 2; j++){
        //         int notdo = prev[j];
        //         if(j == 0) curr[j] = max(notdo,nums[i]-fee + prev[1]);
        //         else    curr[j] = max(notdo,-nums[i] + prev[0]);
        //     }
        //     prev = curr;
        // }
        // return prev[0];
    }
};
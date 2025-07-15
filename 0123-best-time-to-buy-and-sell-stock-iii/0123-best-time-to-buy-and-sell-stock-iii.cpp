class Solution {
//memoization
// public:
//     int fn(int i ,int flg,int ct,vector<int>& nums,vector<vector<vector<int>>>&dp){
//         if(i == 0){
//             if(flg == 1)    return -nums[0];
//             return 0;
//         }
//         if(ct == 0) return 0;
//         if(dp[i][flg][ct] != -1)    return dp[i][flg][ct];
//         int notdo = fn(i-1,flg,ct,nums,dp);
//         if((flg == 1 )  && ct > 0)  return  dp[i][flg][ct] = max(notdo,-(nums[i]) + fn(i-1,0,ct-1,nums,dp));
//         else if(flg == 0 && ct > 0)   return dp[i][flg][ct] = max(notdo,nums[i] + fn(i-1,1,ct,nums,dp));
//         return 0;
//     }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        //memoization
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return fn(n-1,0,2,nums,dp);


        //tabulation
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i = 1; i <= 2; i++){
            dp[0][1][i] = -nums[0];
            dp[0][0][i] = 0;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 1; k < 3; k++){
                    int notdo = dp[i-1][j][k];
                    if(j == 1 && k > 0) dp[i][j][k] = max(notdo,-nums[i]+dp[i-1][0][k-1]);
                    else if(j == 0 && k > 0)    dp[i][j][k] = max(notdo,nums[i]+dp[i-1][1][k]);
                }
            }
        }
        return dp[n-1][0][2];
    }
};
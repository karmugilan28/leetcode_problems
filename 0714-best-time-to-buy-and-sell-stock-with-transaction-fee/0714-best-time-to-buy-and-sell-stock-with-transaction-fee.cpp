class Solution {
    int fn(int i,int op,int fee,vector<int>&nums,vector<vector<int>>&dp){
        if(i == 0){
            if(op == 1) return -nums[i];
            return 0;
        }
        if(dp[i][op] != -1) return dp[i][op];
        int notdo = fn(i-1,op,fee,nums,dp);
        if(op == 0) return dp[i][op] = max(notdo,nums[i]-fee + fn(i-1,1,fee,nums,dp));
        return dp[i][op] = max(notdo,-nums[i] + fn(i-1,0,fee,nums,dp));
    }
public:
    int maxProfit(vector<int>& nums, int fee) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(n-1,0,fee,nums,dp);
    }
};
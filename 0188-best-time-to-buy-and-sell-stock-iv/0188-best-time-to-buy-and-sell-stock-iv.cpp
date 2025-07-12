class Solution {
public:
    int fn(int i,int k,int flg,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i < 0)   return 0;
        if(dp[i][k][flg] != -1) return dp[i][k][flg];
        int notdo = fn(i-1,k,flg,nums,dp);
        int buy = 0, sell = 0;
        if(flg == 0 || flg == 2 && k>0)    buy = -(nums[i]) + fn(i-1,k,1,nums,dp);
        else if(flg == 1 && k > 0)  sell = nums[i] + fn(i-1,k-1,2,nums,dp);
        return dp[i][k][flg] = max(notdo,max(buy,sell));
    }
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();
        reverse(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(3,-1)));
        return fn(n-1,k,0,nums,dp);
    }
};
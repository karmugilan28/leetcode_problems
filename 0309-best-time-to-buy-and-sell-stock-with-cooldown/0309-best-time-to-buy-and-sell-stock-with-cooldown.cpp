class Solution {
public:
    int fn(int i,int last,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0) return 0;
        if(i == 0){
            if(last==1)    return dp[i][last] = -nums[i];
            else    return dp[i][last] = 0;
        }
        if(dp[i][last] != -1)  return dp[i][last];
        int nottake = fn(i-1,last,nums,dp),take = 0;
        if(last == 0)   take = nums[i] + fn(i-1,1,nums,dp);
        else    take = -nums[i] + fn(i-2,0,nums,dp);
        return dp[i][last] = max(take,nottake);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(n-1,0,prices,dp);
    }
};
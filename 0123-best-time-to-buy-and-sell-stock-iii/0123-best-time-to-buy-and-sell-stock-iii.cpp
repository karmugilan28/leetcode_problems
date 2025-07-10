class Solution {
public:
    int fn(int i ,int flg,int ct,vector<int>& nums,vector<vector<vector<int>>>&dp){
        if(i < 0)   return 0;
        int buy = 0,sell = 0;
        if(dp[i][flg][ct] != -1)    return dp[i][flg][ct];
        int notdo = fn(i-1,flg,ct,nums,dp);
        if((flg == 0 || flg == 2)  && ct < 2)
            buy = -(nums[i]) + fn(i-1,1,ct,nums,dp);
        else if(flg == 1 && ct < 2)   sell = nums[i] + fn(i-1,2,ct+1,nums,dp);
        return dp[i][flg][ct] = max(buy,max(sell,notdo));
    }
public:
    int maxProfit(vector<int>& prices) {
        reverse(prices.begin(),prices.end());
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(3,-1)));
        return fn(n-1,0,0,prices,dp);
    }
};
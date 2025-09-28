class Solution {
public:
    int fn(int ind,int n,vector<int>&cost,vector<int>&dp){
        if(ind == n)  return 0;
        if(dp[ind] != -1)   return dp[ind];
        int step1 = 1e9,step2 = 1e9, step3 = 1e9;
        if(ind < n)   step1 = (cost[ind] + 1)+fn(ind+1,n,cost,dp);
        if(ind < n-1)   step2 = (cost[ind+1] + 4)+fn(ind+2,n,cost,dp);
        if(ind < n-2)   step3 = (cost[ind+2] + 9)+fn(ind+3,n,cost,dp);
        return dp[ind] = min(step1,min(step2,step3));
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        int m = costs.size();
        vector<int>dp(n+1,-1);
        return fn(0,n,costs,dp);
    }
};
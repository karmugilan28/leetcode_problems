class Solution {
public:
    int fn(int k,vector<int>&coins,vector<int>&dp){
        if(k<0)
            return 1e8;
        if(k==0)
            return 0;
        if(dp[k]!=-1)
            return dp[k];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int l=1+fn(k-coins[i],coins,dp);
            mini=min(l,mini);
        }
        return dp[k]=mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int k=amount;
        int cnt=0;
        vector<int>dp(k+1,-1);
        int a=fn(k,coins,dp);
        if(a>=1e8)
            return -1;
        return a;
    }
};
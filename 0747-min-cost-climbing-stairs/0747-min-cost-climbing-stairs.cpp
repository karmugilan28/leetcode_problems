class Solution {
public:
    int fn(int i,vector<int>&arr,vector<int>&dp){
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int sum=arr[i]+fn(i+1,arr,dp);
        int summ=arr[i]+fn(i+2,arr,dp);
        return dp[i]=min(sum,summ);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        int a=fn(0,cost,dp);
        int b=fn(1,cost,dp);
        return min(a,b);
    }
};
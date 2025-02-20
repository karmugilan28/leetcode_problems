class Solution {
public:
    int fn(int n,vector<int>&nums,vector<int>&dp){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int l=fn(n-nums[i],nums,dp);
            sum+=l;
        }
        return dp[n]=sum;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return fn(target,nums,dp);
    }
};
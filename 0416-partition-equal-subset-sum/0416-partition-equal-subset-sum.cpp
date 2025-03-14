class Solution {
public:
    int fn(int i,int sum,int add ,vector<int>&arr,vector<vector<int>>&dp){
        if(i<0)
            return sum==add;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int take=fn(i-1,sum+arr[i],add,arr,dp);
        int nottake=fn(i-1,sum,add+arr[i],arr,dp);
        return dp[i][sum]=(take || nottake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return fn(n-1,0,0,nums,dp);
    }
};
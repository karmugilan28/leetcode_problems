class Solution {
public:
    int fn(int i,vector<int>& nums,vector<int>&a,vector<int>&dp){
        if(i==0){
            if(a[0]==0)
                return nums[i];
            return 0;
        }
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(i==nums.size()-1)
            a[0]=1;
        int take=nums[i];
        if(i>1)
            take+=fn(i-2,nums,a,dp);
        else
            take+=0;
        if(i==nums.size()-1)
            a[0]=0;
        int nottake=0+fn(i-1,nums,a,dp);
        return dp[i]=max(take,nottake);
    }
    int fnn(int i,vector<int>& nums,int &ab,vector<int>&dpp){
        if(i==nums.size()-1){
            if(ab==0)
                return nums[i];
            return 0;
        }
        if(i>nums.size()-1)
            return 0;
        if(dpp[i]!=-1)
            return dpp[i];
        if(i==0)
            ab=1;
        int take=nums[i];
        if(i<nums.size()-1)
            take+=fnn(i+2,nums,ab,dpp);
        else
            take+=0;
        if(i==0)
            ab=0;
        int nottake=0+fnn(i+1,nums,ab,dpp);
        return dpp[i]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(1,0);
        vector<int>dp(nums.size(),-1);
        int ans=fn(n-1,nums,a,dp);
        vector<int>dpp(nums.size(),-1);
        int prev=0;
        int res=fnn(0,nums,prev,dpp);
        return max(ans,res);
    }
};
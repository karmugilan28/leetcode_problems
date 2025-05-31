class Solution {
public:
    int fn(int i,int last,vector<int>&nums,vector<vector<int>>&dp){
        if(i==0){
            return nums[0]<last;
        }
        if(dp[i][last]!=-1) return dp[i][last];
        int take=0;
        if(nums[i]<last)
            take+=(1+fn(i-1,nums[i],nums,dp));
        int nottake=0+fn(i-1,last,nums,dp);
        return dp[i][last] = max(take,nottake);   
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int mini=10;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                mini=min(mini,nums[i]);
            }
        }
        if(mini<0){
            for(int i=0;i<n;i++){
                nums[i]+=abs(mini);
            }
        }
        //memoization
        // int maxi=*max_element(nums.begin(),nums.end());
        // vector<vector<int>>dp(n,vector<int>(maxi+2,-1))
        // return fn(n-1,maxi+1,nums,dp);

        //tabulation
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>>dp(n,vector<int>(maxi+2,0));
        for(int j=0;j<=maxi+1;j++)  dp[0][j]=nums[0]<j;

        for(int i=1;i<n;i++){
            for(int j=0;j<=maxi+1;j++){
                int take=0;
                if(nums[i]<j)
                    take+=(1+dp[i-1][nums[i]]);
                int nottake=0+dp[i-1][j];
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[n-1][maxi+1];
        
    }
};
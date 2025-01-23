class Solution {
    //memoization
// public:
//     int fn(int i,vector<int>&nums,vector<int>&dp){
//         if(i==0)
//             return nums[i];
//         if(i<0)
//             return 0;
//         if(dp[i]!=-1)
//             return dp[i];
//         int t=nums[i]+fn(i-2,nums,dp);
//         int nt=0+fn(i-1,nums,dp);
//         return dp[i]=max(t,nt);
//     }
public:
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // return fn(n-1,nums,dp);

        //tabulation - bottom up approach
        // vector<int>dp(nums.size());
        // dp[0]=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     int t=nums[i];
        //     if(i>1)
        //         t+=dp[i-2];
        //     int nt=0+dp[i-1];
        //     dp[i]=max(t,nt);
        // }
        // return dp[nums.size()-1];
        
        //space optimization
        int prev=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int t=nums[i];
            if(i>1)
                t+=prev2;
            int nt=0+prev;
            int cur=max(t,nt);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};
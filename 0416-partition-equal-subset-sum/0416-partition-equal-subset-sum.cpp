class Solution {
// public:
//     int fn(int i,int sum,int add ,vector<int>&arr,vector<vector<int>>&dp){
//         if(i<0)
//             return sum==add;
        
//         if(dp[i][sum]!=-1)
//             return dp[i][sum];
//         int take=fn(i-1,sum+arr[i],add,arr,dp);
//         int nottake=fn(i-1,sum,add+arr[i],arr,dp);
//         return dp[i][sum]=(take || nottake);
//     }
// public:
//     int fn(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
//         if(i<0)
//             return (sum==0);

//         if(dp[i][sum]!=-1)
//             return dp[i][sum];

//         int take=0;
//         if(sum-arr[i]>=0)
//             take=fn(i-1,sum-arr[i],arr,dp);
//         int nottake=fn(i-1,sum,arr,dp);
//         return dp[i][sum]=(take || nottake);
//     }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        // cout << sum << endl;
        if(sum%2!=0)
            return 0;
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        // return fn(n-1,sum/2,nums,dp);
        vector<vector<bool>>dp(n,vector<bool>((sum)+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                int take=0;
                if(j-nums[i]>=0)
                    take=dp[i-1][j-nums[i]];
                int nottake=dp[i-1][j];
                dp[i][j] = (take || nottake);
            }
        }
        return dp[n-1][sum/2];
    }
};
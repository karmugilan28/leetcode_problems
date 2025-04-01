class Solution {
//memoization
// public:
//     long long fn(int i,vector<vector<int>>&arr,vector<long long>&dp){
//         if(i>=arr.size())
//             return 0;

//         if(dp[i] != -1)
//             return dp[i];

//         long long take = arr[i][0] + fn(i+arr[i][1]+1,arr,dp);
//         long long nottake = 0 + fn(i+1,arr,dp);
//         return dp[i] = max(take,nottake);
//     }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<vector<int>>arr(n,vector<int>(2,0));
        arr=questions;
        // vector<long long> dp(n,-1);
        // return fn(0,questions,dp);

        //tabulation
        vector<long long>dp(n,0);
        for(int i=n-1;i>=0;i--){
            long long take = arr[i][0];
            if((i+arr[i][1]+1) < n)
                take += dp[i+arr[i][1]+1];
                
            long long nottake = 0;
            if(i<n-1)
                nottake = dp[i+1];
            dp[i] = max(take,nottake);
        }
        return dp[0];
    }
};
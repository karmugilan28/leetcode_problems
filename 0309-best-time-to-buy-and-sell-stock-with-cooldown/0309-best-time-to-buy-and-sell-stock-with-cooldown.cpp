class Solution {
//memoization
// public:
    // int fn(int i,int last,vector<int>&nums,vector<vector<int>>&dp){
    //     if(i<0) return 0;
    //     if(i == 0){
    //         if(last==1)    return dp[i][last] = -nums[i];
    //         else    return dp[i][last] = 0;
    //     }
    //     if(dp[i][last] != -1)  return dp[i][last];
    //     int nottake = fn(i-1,last,nums,dp),take = 0;
    //     if(last == 0)   take = nums[i] + fn(i-1,1,nums,dp);
    //     else    take = -nums[i] + fn(i-2,0,nums,dp);
    //     return dp[i][last] = max(take,nottake);
    // }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        //memoization
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return fn(n-1,0,prices,dp);

        //tabulation
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[1][1] = -nums[0];
        dp[1][0] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j >=0; j--){
                int nottake = dp[i-1][j];
                int take = 0;
                if(j == 0)   take = nums[i-1] + dp[i-1][1];
                else{
                    if(i>1)  take = -nums[i-1] + dp[i-2][0];
                }
                dp[i][j] = max(nottake,take);
            }
        }
        // for(int i=0 ;i<=n;i++)  cout << dp[i][0] << ' ' << dp[i][1] << endl;
        return dp[n][0];
    }
};
class Solution {
    int MOD = 1e9+7;
    // memoization
    // int fn(int n,int k,int tar,vector<vector<int>>&dp){
    //     int sum = 0;
    //     if(n == 1){
    //         for(int i = 1; i <= k;i++){
    //             if(tar == i)    return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[n][tar] != -1)    return dp[n][tar];
    //     for(int j = 1; j <= k; j++){
    //         int a = 0;
    //         if(tar >= j)    a = fn(n-1,k,tar-j,dp);
    //         sum = (sum + a)%MOD;
    //     }
    //     return dp[n][tar] = sum%MOD;
    // }
public:
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return fn(n,k,target,dp);

        //tabulation
        //base case
        // vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        // for(int j = 1; j <= target; j++){
        //     int flg = 0;
        //     for(int p = 1; p <= k; p++){
        //         if(j == p){
        //             flg = 1;
        //             break;
        //         }
        //     }
        //     if(flg == 1)    dp[1][j] = 1;
        //     else    dp[1][j] = 0;
        // }
        // for(int i = 2; i <= n; i++){
        //     for(int j = 1; j <= target; j++){
        //         int sum = 0;
        //         for(int p = 1; p <= k; p++){
        //             int a = 0;
        //             if(j >= p)  a = dp[i-1][j-p];
        //             sum = (sum + a)%MOD;
        //         }
        //         dp[i][j] = sum;
        //     }
        // }
        // return dp[n][target];

        //space optimization
        vector<int>prev(target+1,0),curr(target+1,0);
        for(int j = 1; j <= target; j++){
            int flg = 0;
            for(int p = 1; p <= k; p++){
                if(j == p){
                    flg = 1;
                    break;
                }
            }
            if(flg == 1)    prev[j] = 1;
            else    prev[j] = 0;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= target; j++){
                int sum = 0;
                for(int p = 1; p <= k; p++){
                    int a = 0;
                    if(j >= p)  a = prev[j-p];
                    sum = (sum + a)%MOD;
                }
                curr[j] = sum;
            }
            prev = curr;
        }
        return prev[target];
    }
};
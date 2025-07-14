class Solution {
    int MOD = 1e9+7;
    int fn(int n,int k,int b,int tar,vector<vector<vector<int>>>&dp){
        int sum = 0;
        if(n == 1){
            for(int i = 1; i <= k;i++){
                if(tar == i)    return 1;
            }
            return 0;
        }
        if(dp[n][b][tar] != -1)    return dp[n][b][tar];
        for(int j = 1; j <= k; j++){
            int a = 0;
            if(tar >= j)    a = fn(n-1,k,j,tar-j,dp);
            sum = (sum + a)%MOD;
        }
        return dp[n][b][tar] = sum%MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(target+1,-1)));
        return fn(n,k,k,target,dp);
    }
};
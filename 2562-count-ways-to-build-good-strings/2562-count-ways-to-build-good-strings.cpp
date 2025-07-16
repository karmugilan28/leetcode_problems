class Solution {
    int MOD = 1e9+7;
    //memeoization
    // int fn(int len,int one,int zero,int low,int high,vector<int>&dp){
    //     if(len > high)  return 0;
    //     if(dp[len] != -1)   return dp[len];
    //     int a = 0, b = 0;
    //     if(len+one >= low && len+one <= high)    a = 1 + fn(len+one,one,zero,low,high,dp);
    //     else    a = fn(len+one,one,zero,low,high,dp);
    //     if(len+zero >= low && len+zero <= high)    b = 1 + fn(len+zero,one,zero,low,high,dp);
    //     else    b = fn(len+zero,one,zero,low,high,dp);
    //     return dp[len] = (a + b)%MOD;
    // }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // vector<int>dp(high+1,-1);
        // return fn(0,one,zero,low,high,dp);

        // tabulation
        vector<int>dp(high+max(one,zero)+2,0);
        dp[high+1] = 0;
        for(int i = high; i >= 0; i--){
            int a = 0, b = 0;
            if(i + one >= low && i+one <= high) a = 1 + dp[i+one];
            else    a = dp[i+one];
            if(i+zero >= low && i+zero <= high) b = 1 + dp[i+zero];
            else    b = dp[i+zero];
            
            dp[i] = (a + b)%MOD;
        }
        return dp[0];
    }
};
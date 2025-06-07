class Solution {
//memoization
// public:
//     int fn(int i,int j,string& s,string& t,vector<vector<int>>&dp){
//         if(i < 0 || j < 0)  return 0;
//         if(dp[i][j] != -1)  return dp[i][j];
//         if(s[i] == t[j])    return dp[i][j] = 1 + fn(i-1,j-1,s,t,dp);
//         else    return dp[i][j] = max(fn(i,j-1,s,t,dp) ,fn(i-1,j,s,t,dp));
//     }
public:
    int minInsertions(string s) {
        //related lcs
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        //memoization
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int f = fn(n-1,n-1,s,t,dp);
        // return n - f;

        //tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
        //         else    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        //     }
        // }
        // return  n - dp[n][n];

        //space optimization
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1])    curr[j] = 1 + prev[j-1];
                else    curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }
        return  n - prev[n];
    }
};
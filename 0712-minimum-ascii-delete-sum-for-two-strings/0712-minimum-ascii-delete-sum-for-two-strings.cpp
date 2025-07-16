class Solution {
//memoization
// public:
//     int fn(int i,int j,string &s,string &t,vector<vector<int>>&dp){
//         if(i < 0 ){
//             int sum = 0;
//             for(int k = 0; k <= j; k++) sum += int(t[k]);
//             return sum; 
//         }
//         if(j < 0){
//             int sum = 0;
//             for(int k = 0; k <= i; k++) sum += int(s[k]);
//             return sum; 
//         }
//         if(dp[i][j] != -1)  return dp[i][j];
//         int take = 0;
//         if(s[i] == t[j])    return dp[i][j] = fn(i-1,j-1,s,t,dp);
//         else{
//             int nottake1 = int(s[i]) + fn(i-1,j,s,t,dp);
//             int nottake2 = int(t[j]) + fn(i,j-1,s,t,dp);
//             return dp[i][j] = min(nottake1,nottake2);
//         }   
//     }
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        //memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return fn(n-1,m-1,s,t,dp);

        //tabulation
        //base case
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // int sum = 0;
        // for(int j = 1; j <= m; j++){
        //     sum += int(t[j-1]);
        //     dp[0][j] = sum;
        // }
        // int sum2 = 0;
        // for(int i = 1; i <= n; i++){
        //     sum2 += int(s[i-1]);
        //     dp[i][0] = sum2;
        // }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         int take = 0;
        //         if(s[i-1] == t[j-1])    dp[i][j] = dp[i-1][j-1];
        //         else{
        //             int nottake1 = int(s[i-1]) + dp[i-1][j];
        //             int nottake2 = int(t[j-1]) + dp[i][j-1];
        //             dp[i][j] = min(nottake1,nottake2);
        //         }
        //     }
        // }
        // return dp[n][m];

        // space optimization
        vector<int>prev(m+1),curr(m+1);
        int sum = 0;
        for(int j = 1; j <= m; j++){
            sum += int(t[j-1]);
            prev[j] = sum;
        }
        int sum2 = 0;
        

        for(int i = 1; i <= n; i++){
            sum2 += int(s[i-1]);
            curr[0] = sum2;
            for(int j = 1; j <= m; j++){
                int take = 0;
                if(s[i-1] == t[j-1])    curr[j] = prev[j-1];
                else{
                    int nottake1 = int(s[i-1]) + prev[j];
                    int nottake2 = int(t[j-1]) + curr[j-1];
                    curr[j] = min(nottake1,nottake2);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
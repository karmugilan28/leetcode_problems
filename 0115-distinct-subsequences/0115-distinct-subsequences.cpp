class Solution {
// int fn(int i,int j,string s,string t,vector<vector<int>>&dp){
//     if(j<0) return 1;
//     if(i<0)
//         return 0;
//     if(dp[i][j]!=-1)    return dp[i][j];

//     if(s[i]==t[j]){
//         int take = fn(i-1,j-1,s,t,dp);
//         int nottake = fn(i-1,j,s,t,dp);
//         return dp[i][j]=take+nottake;
//     }
//     else{
//         return  dp[i][j]=fn(i-1,j,s,t,dp);
//     }
// }
public:
    int numDistinct(string s, string t) {
        int n = s.size(),m = t.size();
        //memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // int f = fn(n-1,m-1,s,t,dp);

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    long long take = dp[i-1][j-1];
                    long long nottake = dp[i-1][j];
                    if(take + nottake > INT_MAX)    dp[i][j] = INT_MAX;
                    else    dp[i][j] = take + nottake;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
        
        //tabulation
        // 
        
    }
};
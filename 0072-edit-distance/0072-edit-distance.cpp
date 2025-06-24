class Solution {
// public:
//     int fn(int i,int j,string& s,string& t,vector<vector<int>>&dp){
//         if(j < 0 || i < 0)   return max(i+1,j+1);
//         if(dp[i][j] != -1)  return dp[i][j];
//         if(s[i] == t[j])    return fn(i-1,j-1,s,t,dp);  //match
//         else{   //notmatch
//             int d = 1 + fn(i-1,j,s,t,dp);   //delete
//             int r = 1 + fn(i-1,j-1,s,t,dp); //replace
//             int l = 1 + fn(i,j-1,s,t,dp);   //insert
//             return dp[i][j] = min(d,min(r,l)); //take min of all
//         }
//     }
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>>dp1(n,vector<int>(m,-1));
        // return fn(n-1,m-1,s,t,dp1);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base case
        // for(int j = 0; j <= m; j++)    dp[0][j] = j; 
        // for(int j = 0; j <= n; j++)    dp[j][0] = j;

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(s[i-1] == t[j-1])    dp[i][j] = dp[i-1][j-1];
        //         else{
        //             int d = 1 + dp[i-1][j];
        //             int r = 1 + dp[i-1][j-1];
        //             int l = 1 + dp[i][j-1];
        //             dp[i][j] = min(d,min(r,l));
        //         }
        //     }
        // }
        // return dp[n][m];

        //space optimization
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j = 0; j <= m; j++)    prev[j] = j; 
        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])    curr[j] = prev[j-1];
                else{
                    int d = 1 + prev[j];
                    int r = 1 + prev[j-1];
                    int l = 1 + curr[j-1];
                    curr[j] = min(d,min(r,l));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};  
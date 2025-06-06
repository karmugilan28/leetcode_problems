class Solution {
// int fn(int l,int r,string& s,vector<vector<int>>&dp){
//     if(l>r) return 0;
//     if(l==r)    return  dp[l][r] = 1;
//     if(dp[l][r]!=-1)    return dp[l][r];
//     if(s[l]==s[r])  return dp[l][r] = 2 + fn(l+1,r-1,s,dp);
//     else    return dp[l][r] = max(fn(l+1,r,s,dp),fn(l,r-1,s,dp));
// }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size(),d;
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // int f = fn(0,n-1,s,dp);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        // return f;
        //tabulation
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        int maxi=0;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s[j-1])  dp[i][j] = 1 + dp[i+1][j-1];
                else    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;   
    }
};
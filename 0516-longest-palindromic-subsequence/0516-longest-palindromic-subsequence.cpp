class Solution {
int fn(int l,int r,string& s,vector<vector<int>>&dp){
    if(l>r) return 0;
    if(l==r)    return 1;
    if(dp[l][r]!=-1)    return dp[l][r];
    if(s[l]==s[r])  return dp[l][r] = 2 + fn(l+1,r-1,s,dp);
    else    return dp[l][r] = max(fn(l+1,r,s,dp),fn(l,r-1,s,dp));
}
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fn(0,n-1,s,dp);

        //tabulation
        
    }
};
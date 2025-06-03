class Solution {
public:
    int fn(int i,int j,string& s,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j)    return 1;
        if(dp[i][j]!=-1)    return dp[i][j];
        int pick=0,notpick1=0,notpick2=0;
        if(s[i]==s[j])  pick=2+fn(i+1,j-1,s,dp);
        else{
            notpick1=fn(i+1,j,s,dp);
            notpick2=fn(i,j-1,s,dp);
        }
        return dp[i][j] = max(pick,max(notpick1,notpick2));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fn(0,n-1,s,dp);
    }
};
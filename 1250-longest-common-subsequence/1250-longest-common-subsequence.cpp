class Solution {
public:
    int fn(int i,int j,string&s,string& t,vector<vector<int>>&dp){
        if(i<0 || j<0)  return 0;
        if(i==0 && j==0){
            if(s[i]==t[j])  return 1;
            return 0;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int pick=0;
        if(s[i]==t[j])
            pick=1+fn(i-1,j-1,s,t,dp);
        int notpick1=0+fn(i,j-1,s,t,dp);
        int notpick2=0+fn(i-1,j,s,t,dp);
        return dp[i][j]=max(pick,max(notpick1,notpick2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,text1,text2,dp);
    }
};
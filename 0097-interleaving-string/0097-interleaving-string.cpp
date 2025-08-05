class Solution {
public:
    bool fn(int i ,int j,int k,string& s,string& t,string& z,vector<vector<vector<int>>>&dp){
        if(i == 0 && j == 0 && k == 0)   return true;
        bool take = 0;
        if(dp[i][j][k] != -1)   return dp[i][j][k];
        if(i >= 1 && j >= 1 && s[i-1] == t[j-1])   take = fn(i-1,j-1,k,s,t,z,dp);
        if(i >= 1 && k >= 1 && s[i-1] == z[k-1])   take = take || fn(i-1,j,k-1,s,t,z,dp);
        return dp[i][j][k] = take;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s3.size(), m = s1.size(), k = s2.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return fn(n,m,k,s3,s1,s2,dp);
    }
};
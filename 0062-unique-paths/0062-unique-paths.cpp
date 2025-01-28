class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j==0)
            return 1;
        int l=fn(i-1,j,dp);
        int r=fn(i,j-1,dp);
        return dp[i][j]=l+r;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=fn(m-1,n-1,dp);
        return ans;
    }
};
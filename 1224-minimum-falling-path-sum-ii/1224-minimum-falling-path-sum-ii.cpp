class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&grid,int last,vector<vector<int>>&dp){
        if(i==0){
            int m=INT_MAX;
            for(int g=grid.size()-1;g>=0;g--){
                if(last!=g)
                    m=min(m,grid[i][g]);
            }
            return m;
        }
        if(dp[i][j]!=-100)
            return dp[i][j];
        int mini=INT_MAX,l=INT_MAX;
        for(int k=grid.size()-1;k>=0;k--){
            if(k!=last){
                l=grid[i][k]+fn(i-1,k,grid,k,dp);
                mini=min(l,mini);
            }
        }
        return dp[i][j]=mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-100));
        int minii=INT_MAX;
        for(int j=n-1;j>=0;j--){
            int ans=fn(n-1,j,grid,-1,dp);
            minii=min(minii,ans);
        }
        return minii;
    }
};
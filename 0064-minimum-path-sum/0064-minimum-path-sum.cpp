class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0)
            return 9999999;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=0,r=0;
        l=grid[i][j]+fn(i-1,j,grid,dp);
        cout <<  1 << " " << l << endl;
        r=grid[i][j]+fn(i,j-1,grid,dp);
        cout << -1 << " " <<r << endl;
        return  dp[i][j]=min(l,r);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=fn(m-1,n-1,grid,dp);
        return ans;
    }
};
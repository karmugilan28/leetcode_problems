class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){  
        if(j<0 || j>grid.size()-1)
            return 99999;
        if(dp[i][j]!=-1000)
            return dp[i][j];
        if(i==0 && j>=0)
            return grid[i][j];
        int l=INT_MAX,r=INT_MAX,g=INT_MAX,maxi=999999;
        if(i==grid.size()-1){
            for(int k=grid.size()-1;k>=0;k--){
                l=grid[i][k]+fn(i-1,k,grid,dp);
                r=grid[i][k]+fn(i-1,k-1,grid,dp);
                g=grid[i][k]+fn(i-1,k+1,grid,dp);
                maxi=min(maxi,min(l,min(r,g)));
            }
        }
        else{
            l=grid[i][j]+fn(i-1,j,grid,dp);
            r=grid[i][j]+fn(i-1,j-1,grid,dp);
            g=grid[i][j]+fn(i-1,j+1,grid,dp);
        }
        maxi=min(maxi,min(l,min(r,g)));
        return dp[i][j]=maxi;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1000));
        return fn(n-1,n-1,matrix,dp);
    }
};
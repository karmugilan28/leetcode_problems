class Solution {
public:
    int fn(int i,int j,vector<vector<int>>&grid,int m,vector<vector<int>>& dp){
        if(i!=0)
            if(i>m || j>grid[i-1].size())   return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=grid[i][j]+fn(i+1,j,grid,m,dp);
        int r=grid[i][j]+fn(i+1,j+1,grid,m,dp);
        return dp[i][j]=min(l,r);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp;
        int m=triangle.size();
        for(int i=0;i<m;i++){
            vector<int>nums;
            for(int j=0;j<triangle[i].size();j++){
                nums.push_back(-1);
            }
            dp.push_back(nums);
        }
        int n=m;
        int ans=fn(0,0,triangle,m-1,dp);
        return ans;
    }
};
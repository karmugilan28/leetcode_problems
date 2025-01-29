class Solution {
    //memoization takes O(m-1+n-1)(which the path we take) and space of  of O(n*m) + O(n-+m-1)
// public:
//     int fn(int i,int j,vector<vector<int>>&dp){
//         if(i<0 || j<0)
//             return 0;
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         if(i==0 && j==0)
//             return 1;
//         int l=fn(i-1,j,dp);
//         int r=fn(i,j-1,dp);
//         return dp[i][j]=l+r;
//     }
public:
    int uniquePaths(int m, int n) {
        //memeoization
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=fn(m-1,n-1,dp);
        // return ans;

        //tabulation with space of O(m*n);
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)
        //             dp[i][j]=1;
        //         else{
        //             int l=0,r=0;
        //             if(i>0)
        //                 l=dp[i-1][j];
        //             if(j>0)
        //                 r=dp[i][j-1];
        //             dp[i][j]=l+r;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        //space optimization with O(n);
        vector<int>dp(n,1);
        for(int i=1;i<m;i++){
            int prev=1;
            for(int j=1;j<n;j++){
                dp[j]=dp[j]+prev;
                prev=dp[j];
            }
        }
        return dp[n-1];
    }
};
class Solution {
//memoization
// public:
//     int fn(int i,int j,string&s,string& t,vector<vector<int>>&dp){
//         if(i<0 || j<0)  return 0;
//         if(i==0 && j==0){
//             if(s[i]==t[j])  return 1;
//             return 0;
//         }
//         if(dp[i][j]!=-1)    return dp[i][j];
//         int pick=0;
//         if(s[i]==t[j])
//             pick=1+fn(i-1,j-1,s,t,dp);
//         int notpick1=0+fn(i,j-1,s,t,dp);
//         int notpick2=0+fn(i-1,j,s,t,dp);
//         return dp[i][j]=max(pick,max(notpick1,notpick2));
//     }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        //memoization
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return fn(m-1,n-1,text1,text2,dp);

        //tabulation
        string s=text1,t=text2;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            if(s[0]==t[j])  dp[0][j]=1;
            if(j>0) dp[0][j]=max(dp[0][j],dp[0][j-1]);
        }

        for(int i=0;i<m;i++){
            if(s[i]==t[0])  dp[i][0]=1;
            if(i>0) dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int pick=0;
                if(s[i]==t[j])  pick=1+dp[i-1][j-1];
                int notpick1 = dp[i][j-1];
                int notpick2 = dp[i-1][j];
                dp[i][j] = max(pick,max(notpick1,max(notpick2,dp[i][j])));
            }
        }
        return dp[m-1][n-1];
    }
};
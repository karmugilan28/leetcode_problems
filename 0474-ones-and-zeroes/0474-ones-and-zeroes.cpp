class Solution {
//memoization
// public:
//     int fn(int i,int tarm,int tarn,vector<string>& s,vector<vector<vector<int>>>&dp){
//         int ct=0,cnt=0;
//         for(int j=0;j<s[i].size();j++){
//             if(s[i][j]=='1')   ct++;
//             else    cnt++;
//         }
//         if(i==0){
//             if(tarm>=cnt && tarn>=ct)   return 1;
//             return 0;
//         }
//         if(dp[i][tarm][tarn]!=-1)   return dp[i][tarm][tarn];
//         int take=0;
//         if(tarm>=cnt && tarn>=ct)
//             take=1+fn(i-1,tarm-cnt,tarn-ct,s,dp);
//         int nottake=fn(i-1,tarm,tarn,s,dp);
//         return dp[i][tarm][tarn]=max(take,nottake);
//     }
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        int num=s.size();
        //memoization
        // vector<vector<vector<int>>>dp(k,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // return fn(k-1,m,n,strs,dp);

        //tabulation
        vector<vector<vector<int>>>dp(num,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        int cnt=0,ct=0;
        for(int j=0;j<s[0].size();j++){
            if(s[0][j]=='0')   cnt++;
            else    ct++;
        }
        for(int j=0;j<=m;j++){
            for(int k=0;k<=n;k++){
                if(j>=cnt && k>=ct) dp[0][j][k]=1;
            }
        }
        for(int i = 1; i < num; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    ct = 0,cnt = 0;
                    for(int g = 0; g < s[i].size(); g++){
                        if(s[i][g] == '0')   cnt++;
                        else    ct++;
                    }
                    int take=0;
                    if(j >= cnt && k >= ct) take = 1 + dp[i-1][j-cnt][k-ct];
                    int nottake = dp[i-1][j][k];
                    dp[i][j][k] = max(take,nottake);
                }
            }
        }
        return dp[num-1][m][n];
    }
};
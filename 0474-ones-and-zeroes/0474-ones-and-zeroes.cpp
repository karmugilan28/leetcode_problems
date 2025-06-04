class Solution {
public:
    int fn(int i,int tarm,int tarn,vector<string>& s,vector<vector<vector<int>>>&dp){
        int ct=0,cnt=0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]=='1')   ct++;
            else    cnt++;
        }
        if(i==0){
            if(tarm>=cnt && tarn>=ct)   return 1;
            return 0;
        }
        if(dp[i][tarm][tarn]!=-1)   return dp[i][tarm][tarn];
        int take=0;
        if(tarm>=cnt && tarn>=ct)
            take=1+fn(i-1,tarm-cnt,tarn-ct,s,dp);
        int nottake=fn(i-1,tarm,tarn,s,dp);
        return dp[i][tarm][tarn]=max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<vector<vector<int>>>dp(k,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return fn(k-1,m,n,strs,dp);
    }
};
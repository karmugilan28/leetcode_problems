class Solution {
public:
    long long fn(int i,int last,vector<int>&a,vector<int>&b,vector<vector<long long>>&dp){
        if(i==0){
            if(last==0) return a[0];
            else    return b[0];
        }
        if(dp[i][last]!=-1) return dp[i][last];
        long long change=0;
        if(i>1){
            if(last==0) change=a[i]+fn(i-2,1,a,b,dp);
            else    change=b[i]+fn(i-2,0,a,b,dp);
        }
        long long nochange=0;
        if(last==0) nochange=a[i]+fn(i-1,last,a,b,dp);
        else    nochange=b[i]+fn(i-1,last,a,b,dp);
        return dp[i][last] = max(change,nochange);
    }
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        long long ab=fn(n-1,0,a,b,dp);
        for(int i=0;i<n;i++)    fill(dp[i].begin(),dp[i].end(),-1);
        long long ba=fn(n-1,1,a,b,dp);
        return max(ab,ba);
    }
};
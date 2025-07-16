class Solution {
public:
    int fn(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i < 0 ){
            int sum = 0;
            for(int k = 0; k <= j; k++) sum += int(t[k]);
            return sum; 
        }
        if(j < 0){
            int sum = 0;
            for(int k = 0; k <= i; k++) sum += int(s[k]);
            return sum; 
        }
        if(dp[i][j] != -1)  return dp[i][j];
        int take = 0;
        if(s[i] == t[j])    return dp[i][j] = fn(i-1,j-1,s,t,dp);
        else{
            int nottake1 = int(s[i]) + fn(i-1,j,s,t,dp);
            int nottake2 = int(t[j]) + fn(i,j-1,s,t,dp);
            return dp[i][j] = min(nottake1,nottake2);
        }   
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,s1,s2,dp);
    }
};
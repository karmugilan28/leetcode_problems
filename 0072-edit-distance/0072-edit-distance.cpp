class Solution {
public:
    int fn(int i,int j,string& s,string& t,vector<vector<int>>&dp){
        if(j < 0 || i < 0)   return max(i+1,j+1);
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == t[j])    return fn(i-1,j-1,s,t,dp);
        else{
            int d = 1 + fn(i-1,j,s,t,dp);
            int r = 1 + fn(i-1,j-1,s,t,dp);
            int l = 1 + fn(i,j-1,s,t,dp);
            return dp[i][j] = min(d,min(r,l));
        }
    }
// public:
//     int fn(int i,int j,string& s,string& t){
//         if(j < 0 || i < 0)   return max(i+1,j+1);
//         if(s[i] == t[j])    return fn(i-1,j-1,s,t);
//         else{
//             int d = 1 + fn(i-1,j,s,t);
//             int r = 1 + fn(i-1,j-1,s,t);
//             int l = 1 + fn(i+1,j-1,s,t);
//             return min(d,min(r,l));
//         }
//     }
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp1(n,vector<int>(m,-1));
        return fn(n-1,m-1,s,t,dp1);
        // vector<vector<int>>dp2(m,vector<int>(n,-1));
        // int d = fn(m-1,n-1,s,t,dp2);
        // return min(c,d);
    }
};  
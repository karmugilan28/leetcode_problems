class Solution {
public: 
    bool fn(int i ,int j,string& s,string& p,vector<vector<int>>&dp){
        if(j < 0){
            if(i < 0)   return true;
            return false;
        }
        if(i < 0){
            int k = j+1;
            while(k!=0){
                if(p[k-1] != '*')   return false;
                k--;
            }
            return true;
        }
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = fn(i-1,j-1,s,p,dp);
        if(p[j] == '*'){
            bool no = fn(i,j-1,s,p,dp);
            bool yes = fn(i-1,j,s,p,dp);
            return dp[i][j] = yes || no;
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,s,p,dp);
    }
};
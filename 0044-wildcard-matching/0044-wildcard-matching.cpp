class Solution {
public: 
    bool fn(int i ,int j,string& s,string& p,vector<vector<int>>&dp){
        if(j == -1){
            if(i == -1)   return true;
            return false;
        }
        if(i == -1){
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
        //memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return fn(n-1,m-1,s,p,dp);
        //tabulation
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) dp[i][0] = false;
        for(int j = 1; j <= m; j++){
            int k = j,flg = 0;
            while(k != 0){
                if(p[k-1] != '*'){
                    flg = 1;
                    break;
                }
                k--;
            }
            if(flg == 1)    dp[0][j] = false;
            else    dp[0][j] = true;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*'){
                    bool no = dp[i][j-1];
                    bool yes = dp[i-1][j];
                    dp[i][j] = yes || no;
                }
                else    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
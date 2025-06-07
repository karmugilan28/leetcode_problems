class Solution {
public:
    int minDistance(string s, string t) {
        //relate to lcs -> longest commmon subsequence
        // minimum no. of deletions operations to make s and 1 equal = max number of subsequent elemnts common in s and t;
        int n=s.size(),m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= m; j++){
                if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
                else    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (n+m)-(dp[n][m]*2);
    }
};
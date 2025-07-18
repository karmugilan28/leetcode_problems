class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //related to lcs
        // we need to form string s from which we can able to form the subsequence str1 and str2 with minimum length
        // we can only reduce the length when we common subsequence in both string in str1 and str2 and make them appear once in our resultant string s 
        // so create dp table for lcs
        string s = str1, t = str2;
        int n = s.size() ,m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
                else    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //do backtrack from dp[n][m]
        int i = n ,j = m;
        string res = "";
        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                //if the element matches take it one time and move to i-1 and j-1
                res += s[i-1];
                i--;j--;
            }
            else{
                //if it does not matches  there are two possibilities that we have got our current value from dp[i-1][j] or dp[i][j-1] since we take max from these

                if(dp[i-1][j] >= dp[i][j-1]){
                    //if this happens i take the element from s string and move to i--;
                    res += s[i-1];
                    i--;
                }
                else{
                    // if tjis happens i take the elemnt from t string and move to j--;
                    res += t[j-1];
                    j--;
                }
            }
        }
        // the above loop stops if (i or j)  equals 0 . so i may miss some characters. in order avoid this avoid write the below code
        //and reverse the entire string since we came from last cell of dp table
        while(i){
            res += s[i-1];
            i--;
        }
        while(j){
            res += t[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
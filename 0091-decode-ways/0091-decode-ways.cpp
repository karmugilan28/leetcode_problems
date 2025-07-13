class Solution {
public:
    int fn(int i,int flg,string& s,vector<vector<int>>&dp){
        if(i == s.size())   return 1;
        if(dp[i][flg] != -1)    return dp[i][flg];
        int one = 0,two = 0;
        if(s[i] != '0' )    one = fn(i+1,1,s,dp);
        if(flg == 1){
            string res = "";
            res.push_back(s[i-1]);
            res.push_back(s[i]);
            int num = stoi(res);
            if(num <= stoi("26"))   two = fn(i+1,0,s,dp);
        }
        return dp[i][flg] = one+two;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] =='0'){
                if(i == 0)  return 0;
                else{
                    if(s[i-1] !='1' && s[i-1] != '2')   return 0;
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fn(0,0,s,dp);
    }
};
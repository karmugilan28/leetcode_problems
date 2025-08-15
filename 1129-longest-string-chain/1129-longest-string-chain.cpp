class Solution {
public:
    int fn(int i ,int prev,vector<string>&words,vector<vector<int>>&dp){
        if(i >= words.size()+1)   return 0;
        int take = 0;
        int ct = 0,flg = 0;
        if(dp[i][prev] != -1)   return dp[i][prev];
        if(prev > 0){
            int l = words[i-1].size()-1, r = words[prev-1].size()-1;
            while(l >= 0 && r >= 0){
                if(words[i-1][l] == words[prev-1][r]){
                    l--;r--;
                }
                else   {ct++;l--;}
            }
            if(ct == 0 && l == 0)   flg = 1;
        }
        if(ct == 1 && (words[i-1].size() == words[prev-1].size()+1))    flg = 1;
        if(prev == 0 || flg) take = 1 + fn(i+1,i,words,dp);
        int nottake = fn(i+1,prev,words,dp);
        return dp[i][prev] = max(take,nottake);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](const string a,const string b){
            return a.size() < b.size();
        });
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fn(1,0,words,dp);
    }
};
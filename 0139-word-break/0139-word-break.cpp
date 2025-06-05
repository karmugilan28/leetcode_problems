class Solution {
bool fn(int i,string& s,vector<string>& str,vector<int>& dp){
    if(i<0){
        return 1;
    }
    if(dp[i]!=-1)   return dp[i];
    bool take=0,nottake=0;
    for(int j=0;j<str.size();j++){
        int flg=0,temp=i;
        for(int k=str[j].size()-1;k>=0;k--){
            if(temp>=0 && s[temp]==str[j][k]){
                flg=0;
                temp--;
            }
            else{
                flg=1;
                break;
            }
        }
        if(flg==0){
            take = take || fn(i-str[j].size(),s,str,dp);
            
        }
    }
    return dp[i] = take ;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(s.size(),-1);
        return fn(n-1,s,wordDict,dp);
    }
};
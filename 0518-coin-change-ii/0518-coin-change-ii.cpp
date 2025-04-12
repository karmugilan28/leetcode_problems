class Solution {
// public:
//     int fn(int k,vector<int>&coins){
//         //base condition
//         if(k<0)  return 0;
//         if(k==0)  return 1;
//         int sum=0;
//         for(int i=0;i<coins.size();i++){
//             int l=fn(k-coins[i],coins);
//             sum+=l;
//         }
//         return sum;      
//     }
int fn(int i,int k,vector<int>&coins,vector<vector<int>>&dp){
    if(k==0)    return 1;
    if(k<0)
        return 0;
    if(dp[i][k]!=-1)
        return dp[i][k];
    int sum=0;
    for(int j=i;j>=0;j--){
        int l=fn(j,k-coins[j],coins,dp);
        sum+=l;
    }
    return dp[i][k]=sum;
}
public:
    int change(int amount, vector<int>& coins) {
        int k=amount;
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return fn(n-1,k,coins,dp);
    }
};
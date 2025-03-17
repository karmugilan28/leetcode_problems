class Solution {
public:
    long long fn(int i,vector<vector<int>>&arr,vector<long long>&dp){
        if(i>=arr.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];
            
        long long take = arr[i][0] + fn(i+arr[i][1]+1,arr,dp);
        long long nottake = 0 + fn(i+1,arr,dp);
        return dp[i] = max(take,nottake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return fn(0,questions,dp);
    }
};
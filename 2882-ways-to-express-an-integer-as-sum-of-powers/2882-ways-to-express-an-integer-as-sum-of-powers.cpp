class Solution {
public:
    int fn(int i,int tar,vector<int>&arr,vector<vector<long long>>&dp){
        if(tar == 0)    return 1;
        if(i >= arr.size())  return 0;
        if(dp[i][tar] != -1)    return dp[i][tar];
        long long take = 0;
        if(arr[i] <= tar)   take = fn(i+1,tar-arr[i],arr,dp);
        long long nottake = fn(i+1,tar,arr,dp);
        return dp[i][tar] = (take+nottake)%int(1e9+7);
    }
public:
    int numberOfWays(int n, int x) {
        int temp = 0;
        vector<int>arr;
        for(int i = 1; i <= n; i++){
            int b = pow(i,x);
            if(b <= n){
                arr.push_back(b);
            }
            else    break;
        }
        // for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
        // cout << endl;
        // return 0;
        vector<vector<long long>>dp(n,vector<long long>(n+1,-1));
        return fn(0,n,arr,dp);

    }
};
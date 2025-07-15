class Solution {
//memoization
// public:
//     long long fn(int i, int buy,int k,vector<int>&nums,vector<vector<vector<long long>>>&dp){
//         if(i == 0){
//             if(buy == 0)    return -nums[i];
//             if(buy == 2)    return nums[i];
//             return 0;
//         }
//         if(k == 0)  return 0;
//         if(dp[i][buy][k] != -1) return dp[i][buy][k];
//         //transaction 1
//         long long notdo = fn(i-1,buy,k,nums,dp),tar1 = -1e9,tar2 = -1e9,tar3 = -1e9, tar4 = -1e9;
//         if((buy == 1 || buy == 3)&& k > 0)   tar1 = max(notdo,nums[i] +fn(i-1,0,k,nums,dp));
//         else if((buy == 0) && k > 0)   tar2 = max(notdo,-nums[i]+fn(i-1,1,k-1,nums,dp));

//         //transaction 2
//         if((buy == 3 || buy == 1)&& k > 0)   tar3 = max(notdo,-nums[i]+fn(i-1,2,k,nums,dp));
//         else if((buy == 2)&& k > 0)  tar4 = max(notdo,nums[i]+fn(i-1,3,k-1,nums,dp));
//         return dp[i][buy][k] = max(tar1,max(tar2,max(tar3,tar4)));
//     }
public:
    long long maximumProfit(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(4,vector<long long>(k+1,-1)));
        // return fn(n-1,1,k,prices,dp);

        //tabulation
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(4,vector<long long>(k+1,0)));
        for(int i = 1; i <= k; i++){
            dp[0][0][i] = -nums[0];
            dp[0][2][i] = nums[0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 4; j++){
                for(int g = 1; g <= k; g++){
                    long long notdo = dp[i-1][j][g],tar1=-1e9,tar2=-1e9,tar3=-1e9,tar4=-1e9;
                    //transaction 2
                    if((j == 1 || j == 3) && g > 0) tar1 = nums[i] + dp[i-1][0][g];
                    else if(j == 0 && g > 0)    tar2 = -nums[i] + dp[i-1][1][g-1];

                    //transaction 1
                    if((j == 1 || j == 3) && g > 0) tar3 = -nums[i] + dp[i-1][2][g];
                    else if(j == 2 && g > 0)    tar4 = nums[i] + dp[i-1][3][g-1];
                    dp[i][j][g] = max(tar1,max(tar2,max(tar3,max(notdo,tar4))));
                }
            }
        }
        return dp[n-1][3][k];
    }
};
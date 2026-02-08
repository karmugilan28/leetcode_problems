class Solution {
// public:
//     long long fn(int i,int j,int k,vector<int>&nums1,vector<int>&nums2,vector<vector<vector<long long>>>&dp){
//         if(k == 0)  return 0;
//         if(i >= nums1.size())   return -1e16;
//         if(j >= nums2.size())   return -1e16;
//         if(dp[i][j][k] != -1)   return dp[i][j][k];
//         long long take = 0;
//         if(k > 0)   take = (long long)nums1[i]*(long long)nums2[j] + fn(i+1,j+1,k-1,nums1,nums2,dp);
//         long long nt1 = fn(i+1,j,k,nums1,nums2,dp);
//         long long nt2 = fn(i,j+1,k,nums1,nums2,dp);
//         // long long nt3 = fn(i+1,j+1,k,nums1,nums2,dp);
//         // long long maxi = -1e9;
//         // if(take != -1e9)   maxi = max(maxi,take);
//         // if(nt1 != -1e9)    maxi = max(maxi,nt1);
//         // if(nt2 != -1e9)    maxi = max(maxi,nt2);
//         // if(nt3 != -1e9)    maxi = max(maxi,nt3);
//         return dp[i][j][k] = max({nt1,take,nt2});
//     }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,-1e16)));
        // long long res = fn(0,0,k,nums1,nums2,dp);
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                dp[i][j][0] = 0;
            }
        }
        long long maxi = -1e16;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                for(int g = 1; g <= k; g++){
                    long long take = 0;
                    if(g >= 1)   take = (long long)nums1[i]*(long long)nums2[j] + dp[i+1][j+1][g-1];
                    long long nt1 = dp[i+1][j][g];
                    long long nt2 = dp[i][j+1][g];
                    dp[i][j][g] = max({take,nt1,nt2});
                    // maxi = max(maxi,dp[i][j][g]);
                }
            }
        }
        return dp[0][0][k];
    }
};
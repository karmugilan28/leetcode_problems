class Solution {
public:
    int fn(int i,int flg ,int prev,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(i == nums.size()) return 0;
        int take = 0;
        if(dp[i][flg][prev] != -1)  return dp[i][flg][prev];
        if(flg == 0){
            if(nums[i] > nums[prev])
                take = 1+fn(i+1,1,i,nums,dp);
        }
        else{
            if(nums[i] < nums[prev])
                take = 1 +fn(i+1,0,i,nums,dp);
        }
        int nottake = 0 + fn(i+1,flg,prev,nums,dp);
        return dp[i][flg][prev] = max(take, nottake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1(n),arr2(n);
        arr1 = nums;
        arr2 = nums;
        vector<vector<vector<int>>>dp1(n+1,vector<vector<int>>(2,vector<int>(n+1,-1)));
        arr1.insert(arr1.begin(),1e9);
        arr2.insert(arr2.begin(),-1e9);
        int a = fn(1,1,0,arr1,dp1);
        vector<vector<vector<int>>>dp2(n+1,vector<vector<int>>(2,vector<int>(n+1,-1)));
        int b = fn(1,0,0,arr2,dp2);
        return max(a,b);
    }
};
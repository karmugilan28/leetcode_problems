class Solution {
//backtracking 
// public:
//     void fn(int i,vector<int>&nums,int tar,int sum,int &cnt){
//         if(i>=nums.size()){
//             if(sum==tar){
//                 cnt++;
//             }
//             return ;
//         }
//         fn(i+1,nums,tar,sum+(nums[i]*1),cnt);
//         fn(i+1,nums,tar,sum+(nums[i]*(-1)),cnt);
//         return ;
//     }

//dp
//memoization
public:
    int fn(int i,vector<int>&nums,int tar){
        if(i==nums.size()){
            if(tar==0)
                return 1;
            return 0;
        }
        int l=fn(i+1,nums,tar-nums[i]*(-1));
        int r=fn(i+1,nums,tar-nums[i]);
        return l+r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int>dp(nums.size(),-10000);
        return fn(0,nums,target);
    }
};
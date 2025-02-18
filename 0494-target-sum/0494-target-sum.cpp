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
public:
    int fn(int i,vector<int>&nums,int tar,int sum){
        if(i==nums.size()){
            if(sum==tar)
                return 1;
            return 0;
        }
        return fn(i+1,nums,tar,sum+(nums[i]*(-1)))+fn(i+1,nums,tar,sum+nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return fn(0,nums,target,0);
    }
};
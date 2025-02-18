class Solution {
public:
    void fn(int i,vector<int>&nums,int tar,int sum,int &cnt){
        if(i>=nums.size()){
            if(sum==tar){
                cnt++;
            }
            return ;
        }
        fn(i+1,nums,tar,sum+(nums[i]*1),cnt);
        fn(i+1,nums,tar,sum+(nums[i]*(-1)),cnt);
        return ;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt=0;
        fn(0,nums,target,0,cnt);
        return cnt;
    }
};
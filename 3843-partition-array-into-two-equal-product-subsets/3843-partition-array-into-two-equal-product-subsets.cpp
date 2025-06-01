class Solution {
public:
    bool fn(int i,long long tar,long long pro,vector<int>&nums,long long target){
        if(i<0)
            return (tar==pro && tar==target);
        if(pro>target || tar>target)    return false;
        bool t=fn(i-1,tar*nums[i],pro,nums,target);
        bool nt=fn(i-1,tar,pro*nums[i],nums,target);
        return t || nt;
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        return fn(n-1,1,1,nums,target);
    }
};
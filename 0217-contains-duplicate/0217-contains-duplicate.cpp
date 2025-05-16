class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]>=2) return true;
        }
        return false;
    }
};
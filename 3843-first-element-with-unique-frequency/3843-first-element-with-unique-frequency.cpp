class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp,mp;
        for(int i = 0; i < n; i++)  mpp[nums[i]]++;
        for(auto&it:mpp){
            mp[it.second] += 1;
        }
        for(auto it: nums){
            if(mp[mpp[it]] == 1)    return it;
        }
        return -1;
    }
};
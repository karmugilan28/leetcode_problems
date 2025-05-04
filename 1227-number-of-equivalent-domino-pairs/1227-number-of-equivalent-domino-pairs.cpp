class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            sort(nums[i].begin(),nums[i].end());
        map<vector<int>,int>mpp;
        for(int i=0;i<n;i++)
            mpp[nums[i]]+=1;
        int ct=0;
        for(auto &it:mpp){
            if(it.second>=2){
                ct+=(it.second*(it.second-1))/2;
            }
        }
        return ct;
    }
};
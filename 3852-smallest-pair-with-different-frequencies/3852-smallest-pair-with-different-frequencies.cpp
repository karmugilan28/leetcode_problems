class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int ct = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == mini) ct++;
        }
        map<int,int>mpp;
        for(int i = 0; i < n; i++){
            if(nums[i] != mini){
                mpp[nums[i]]++;
            }
        }
        for(auto&it:mpp){
            if(it.second != ct) return {mini,it.first};
        }
        return {-1,-1};
    }
};
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mpp;
        for(int i = 0; i < n; i++)  mpp[nums1[i]]++;
        for(int i = 0; i < n; i++)  mpp[nums2[i]]++;

        for(auto&it:mpp){
            if(it.second%2 != 0)    return -1;
        }

        unordered_map<int,int>diff;
        for(int i = 0; i < n; i++)  diff[nums1[i]]++;
        for(int i = 0; i < n; i++)  diff[nums2[i]]--;

        long long sum = 0;
        for(auto&it:diff){
            sum += abs((long long)it.second);
        }
        return sum/4;
    }
};
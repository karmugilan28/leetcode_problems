class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size(),ct = 0;
        for(int i = 0; i < n; i++){
            long long a = 1;
            for(int j = i; j < n; j++){
                a = lcm(a,(long long)nums[j]);
                if(a > k)   break;
                if(a == k)  ct++;
            }
        }
        return ct;
    }
};
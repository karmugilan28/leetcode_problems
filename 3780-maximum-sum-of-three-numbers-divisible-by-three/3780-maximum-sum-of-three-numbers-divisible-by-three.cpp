class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>zero,one,two;
        for(int i = 0; i < n; i++){
            if(nums[i]%3 == 0)  zero.push_back(nums[i]);
            else if(nums[i]%3 == 1) one.push_back(nums[i]);
            else    two.push_back(nums[i]);
        }
        sort(zero.rbegin(),zero.rend());
        sort(one.rbegin(),one.rend());
        sort(two.rbegin(),two.rend());
        int maxi = 0;
        if(zero.size() >= 3)    maxi = (zero[0]+zero[1]+zero[2]);
        if(one.size() >= 3)    maxi = max(maxi,one[0]+one[1]+one[2]);
        if(two.size() >= 3)    maxi = max(maxi,two[0]+two[1]+two[2]);
        if(zero.size() >= 1 && one.size() >= 1 && two.size() >= 1)  maxi = max(maxi,(one[0]+two[0]+zero[0]));
        return maxi;
    }
};
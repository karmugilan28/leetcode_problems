class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int pos;
        int flg = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                pos = i;
                if(pos == 0 || pos == n-1){
                    flg = 1;
                    break;
                }
            }
        }
        if(flg) return maxi;
        int mini = min(nums[0],nums[pos]);
        int mini2 = min(nums[pos],nums[n-1]);
        return max(mini,mini2);
    }
};
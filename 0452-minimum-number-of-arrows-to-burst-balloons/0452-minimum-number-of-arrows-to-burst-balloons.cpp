class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = INT_MIN, maxi = INT_MAX;
        int flg = 0,ct = 0;
        for(int i = 0; i < n; i++){
            if(nums[i][0] >= mini && nums[i][0] <= maxi){
                flg = 0;
                mini = max(mini,nums[i][0]);
                maxi = min(maxi,nums[i][1]);
            }
            else{
                flg = 1;
                mini = INT_MIN;
                maxi = INT_MAX;
                ct++;
                i--;
            }
        }
        if(flg == 0)    ct++;
        return ct;
    }
};
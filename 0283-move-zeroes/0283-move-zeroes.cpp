class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int ct = 0,cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[ct] = nums[i];
                ct++;
            }
            else    cnt++;
        }
        int i = n-1;
        while(cnt--){
            nums[i] = 0;
            i--;
        }
        return ;
    }
};
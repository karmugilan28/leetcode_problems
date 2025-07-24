class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        vector<int>arr(n);
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) {arr[ct] = nums[i];ct += 2;} 
        }
        ct = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) {arr[ct] = nums[i];ct += 2;}
        }
        return arr;  
    }
};
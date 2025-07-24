class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int ct = 0,cnt = 1;
        vector<int>arr(n);
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) {arr[ct] = nums[i];ct += 2;} 
            if(nums[i] < 0) {arr[cnt] = nums[i];cnt += 2;}
        }
        
        return arr;  
    }
};
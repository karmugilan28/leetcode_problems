class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // int maxi = 0;
        // for(int i = 0; i < n; i++){
        //     int a = nums[i];
        //     maxi = max(maxi,a);
        //     for(int j = i+1; j < n; j++){
        //         a &= nums[j];
        //         maxi = max(maxi,a);
        //     }
        // }
        // int len = 0;
        // for(int i = 0; i < n; i++){
        //     int a = nums[i];
        //     if(maxi == a)   len = max(len,1);
        //     for(int j = i+1; j < n; j++){
        //         a &= nums[j];
        //         if(maxi == a)   len = max(len,j-i+1);
        //     }
        // }
        // return len;
        int len = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int avg = maxi;
        int mxi = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                len++;
                mxi = max(mxi,len);
            }
            else{
                len = 0;
            }
        }
        return mxi;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // int n = nums.size();
        // int l = 0,r = 0;
        // int ct1 = 0,ct0 = 0;
        // int maxi = 0;
        // while(r < n){
        //     if(nums[r] == 1)    ct1++;
        //     else    ct0++;
        //     if(ct1 == ct0)    maxi = max(maxi,r-l+1);
        //     while( && l < n){
        //         if(nums[l] == 0)    ct0--;
        //         else    ct1--;
        //         l++;
        //     }
        //     if(ct1 == ct0)
        //         maxi=max(maxi,r-l+1);
        //     r++;
        // }
        // return maxi;

        // int n = nums.size(); 
        // int dp[n] = {0}; 
        // int count = 0; 
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0){
        //         count ++; 
        //     }
        //     else count --; 
        //     dp[i] = abs(count); 
        // }
        // int maxi = 0; 
        // for(int i = 0; i < n; i++){
        //     maxi = max(maxi, ())
        // }
        // return nums.size();

        int n = nums.size();
        vector<int>prev(n+2,0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)    sum += -1;
            else    sum += 1;
            prev[i+2] = sum;
        }
        map<int,int>mpp;
        mpp[prev[1]] = 1; 
        int maxi = 0; 
        for(int i = 2; i <= n+1; i++){
            if(mpp[prev[i]])    maxi = max(maxi,i-mpp[prev[i]]);
            else    mpp[prev[i]] = i;
        }
        return maxi;
    }
};
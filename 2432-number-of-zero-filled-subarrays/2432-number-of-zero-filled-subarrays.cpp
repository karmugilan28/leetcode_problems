class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int cnt = 0;
        //     for(int j = i; j < n; j++){
        //         if(nums[j] == 0)    cnt++;
        //         if(cnt == j-i+1)    ans++;
        //     }
        // }
        // return ans;

        // int l = 0, r = 0;
        // int cnt= 0;
        // while(r < n){
        //     if(nums[r] == 0)    cnt++;
        //     while(cnt < (r-l+1) && l <= r){
        //         if(nums[l] == 0)    cnt--;
        //         l++;
        //     }
        //     if(cnt > 0 && cnt == (r-l+1))  ans++;
        //     r++;
        // }
        // return ans;
        long long cnt = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)    cnt++;
            else{
                sum += (cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        if(cnt > 0) sum += (cnt*(cnt+1))/2;
        return sum;
    }
};
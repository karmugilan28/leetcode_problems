class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n=nums.size();
        int c=*max_element(nums.begin(),nums.end());
        long long l=0,r=0;
        long long ct=0,cnt=0;
        while(r<n){
            if(nums[r]==c)
                ct++;
            while(ct>=k){
                cnt+=(n-r);
                if(nums[l]==c)
                    ct--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};
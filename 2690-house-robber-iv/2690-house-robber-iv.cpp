class Solution {
public:
    bool rob(int mid,int k,vector<int>&nums){
        int i=0;
        int cnt=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                i+=2;
                cnt+=1;
            }
            else
                i+=1;
        }
        return cnt>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(rob(mid,k,nums)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};
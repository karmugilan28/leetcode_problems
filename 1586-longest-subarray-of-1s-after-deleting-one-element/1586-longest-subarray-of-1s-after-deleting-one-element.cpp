class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0,maxi=0;
        map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]+=1;
            if(mpp[0]>1){
                mpp[nums[l]]-=1;
                l++;
            }
            if(mpp[0]<=1)
                maxi=max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};
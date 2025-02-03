class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int len=1,maxlen=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                len++;
                maxlen=max(maxlen,len);
            }
            else{
                len=1;
                maxlen=max(maxlen,len);
            } 
        }
        int leni=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                leni++;
                maxlen=max(maxlen,leni);
            }
            else{
                leni=1;
                maxlen=max(maxlen,leni);
            }
        }
        return maxlen;
    }
};
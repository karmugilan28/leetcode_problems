class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        for(int j=maxi;j>=0;j--){
            int ct=0;
            for(int i=n-1;i>=0;i--){
                if(nums[i]>=j)
                    ct++;
            }
            if(ct>=j)
                return j;
        }
        return 0;
    }
};
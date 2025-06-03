class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=INT_MAX;
        int l=1,r=maxi;
        while(l<=r){
            int mid=(l+r)/2;
            long long sum=0;
            for(int j=0;j<n;j++){
                if((long long)nums[j]%mid!=0)    sum+=(((long long)nums[j]/mid)+1);
                else    sum+=((long long)nums[j]/mid);
            }
            if(sum<=h){
                mini=min(mini,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};
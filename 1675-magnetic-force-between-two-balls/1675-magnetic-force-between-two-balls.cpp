class Solution {
public:
    int maxDistance(vector<int>& nums, int m) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mxi = 0,low = 1,high = nums[n-1]-nums[0];
        while(low <= high){
            int mid = (low+high)/2;
            // cout << mid << endl;
            int prev = nums[0],ct = 1;
            for(int j = 1; j < n; j++){
                if(nums[j]-prev >= mid){
                    ct++;
                    prev = nums[j];
                }
            }

            if(ct >= m){
                mxi = max(mxi,mid);
                low = mid+1;
            }
            else if(ct < m)
                high = mid-1;
        }
        return mxi;
    }
};
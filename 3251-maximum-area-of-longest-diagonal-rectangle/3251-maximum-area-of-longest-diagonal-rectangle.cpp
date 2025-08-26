class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        int n = nums.size();
        map<float,pair<int,int>>mpp;
        float maxi = 0;
        for(int i = 0; i < n; i++){
            float d = sqrt(nums[i][0]*nums[i][0] + nums[i][1]*nums[i][1]);
            mpp[d].first += 1;
            mpp[d].second = max(mpp[d].second,nums[i][0]*nums[i][1]);
            cout << mpp[d].first << " " << mpp[d].second << endl;
            maxi = max(d,maxi);
        }
        return mpp[maxi].second;
    }
};
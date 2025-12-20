class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i = 0; i < n; i++)  mpp[nums[i]]++;
        int curr = n;
        int h = mpp.size(),g = -1,ct = 0;
        for(int i = 0; i <= n-3; i += 3){
            if(h == curr)    break;
            else{
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0)   h--;
                mpp[nums[i+1]]--;
                if(mpp[nums[i+1]] == 0)   h--;
                mpp[nums[i+2]]--;
                if(mpp[nums[i+2]] == 0)   h--;
            }
            g = i;
            ct++;
            curr -= 3;
        }
        int a = n%3;
        if(g != n-1){
            if(curr != h){
                if(a == 1){
                    mpp[nums[n-1]]--;
                    if(mpp[nums[n-1]] == 0)   h--;
                    ct++;
                }
                else if(a == 2){
                    mpp[nums[n-1]]--;
                    if(mpp[nums[n-1]] == 0)   h--;
                    mpp[nums[n-2]]--;
                    if(mpp[nums[n-2]] == 0)   h--;
                    ct++;
                }
            }
        }
        return ct;
    }
};
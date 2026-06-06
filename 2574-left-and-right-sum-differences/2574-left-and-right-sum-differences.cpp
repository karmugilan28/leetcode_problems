class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,0),suff(n,0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            pre[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            suff[i] = sum;
            sum += nums[i];
        }
        vector<int>ans(n,0);
        for(int i = 0; i < n; i++){
            if(i == 0)    ans[i] = suff[i];
            else if(i == n-1)   ans[i] = pre[i];
            else    ans[i] = abs(pre[i]-suff[i]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n),suf(n);
        int pro = 1;
        for(int i=0;i<n;i++){
            pro *= nums[i];
            pre[i] = pro;
        }
        pro = 1;
        for(int i=n-1;i>=0;i--){
            pro*=nums[i];
            suf[i] = pro;
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(i==0)    res[i] = 1*suf[i+1];
            else if(i==n-1)  res[i] = pre[i-1]*1;
            else    res[i] = pre[i-1] * suf[i+1];
        }
        return res;
    }
};
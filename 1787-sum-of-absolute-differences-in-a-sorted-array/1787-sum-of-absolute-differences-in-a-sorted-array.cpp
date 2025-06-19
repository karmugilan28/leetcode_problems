class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int>prev(n,0);
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prev[i] = sum;
        }
        vector<int>res(n);
        for(int i = 0; i < n; i++){
            if(i == 0)    res[i] = sum - ((n-i)*nums[i]);
            else    res[i] = ((sum - prev[i-1]) - ((n-i)*nums[i])) + abs(prev[i-1] - ((i)*nums[i]));
        }
        return res;
    }
};
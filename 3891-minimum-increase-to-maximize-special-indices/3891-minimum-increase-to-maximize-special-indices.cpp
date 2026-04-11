class Solution {
public:
    long long minIncrease(vector<int>& num) {
        int n = num.size();
        vector<long long>nums;
        for(int i = 0; i < n; i++)  nums.push_back((long long)num[i]);
        vector<long long>arr;
        long long sp1 = 0, op1 = 0;
        for(int i = 1; i < n-1; i+=2){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])  sp1++;
            else{
                sp1++;
                op1 += max(nums[i-1],nums[i+1])-nums[i]+1;
            }
        }
        if(n%2 != 0)    return op1;
        long long co = op1;
        arr.push_back(co);
        for(int i = n-2; i >= 2; i -= 2){
            int tem = max(nums[i],nums[i-2])-nums[i-1]+1;
            if(tem > 0) co -= tem;
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1])  {}
            else    co += max(nums[i-1],nums[i+1])-nums[i]+1;
            arr.push_back(co);
            // cout << co << endl;
        }
        long long mini = *min_element(arr.begin(),arr.end());
        return mini;
    }
};
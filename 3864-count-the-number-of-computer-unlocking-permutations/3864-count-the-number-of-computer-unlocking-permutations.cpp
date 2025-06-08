class Solution {
public:
    long long fn(int n){
        if(n<=1)    return 1;        
        return (n * fn(n-1))%(int)(1e9+7);
    }
public:
    int countPermutations(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++)
            if(nums[i]<=nums[0])    return 0;

        int f=fn(n-1);
        return f;
    }
};
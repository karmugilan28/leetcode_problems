class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return abs((long long)nums[0]-(long long)nums[1]);
        }
        int first = 0;
        long long sum = (long long)nums[0];
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1]){
                first = i+1;
                sum += (long long)nums[i+1];
            }
            else    break;
        }
        int last = first+1;
        long long sum2 = (long long)nums[first+1];
        for(int i = first+1; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                last = i+1;
                sum2 += (long long)nums[i+1];
            }
            else    break;
        }
        int flg = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1]) flg = 0;
            else{
                flg = 1;
                break;
            }
        }
        if(flg == 0){
            long long a = sum-nums[n-1];
            long long b = sum2+nums[n-1];
            return abs(b-a);
        }
        if(last != n-1) return -1;
        long long temp = sum-nums[first];
        long long ans1 = abs(sum-sum2),ans2 = abs(temp - (sum2+nums[first]));
        return min(ans1,ans2);
    }
};
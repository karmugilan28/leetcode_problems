class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<int>a,b;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == 0 || i == 1){
                a.push_back(nums[i]);
                continue;
            }
            else if(i == 2){
                b.push_back(nums[i]);
                continue;
            }
            int flg = 0;
            for(int j = 2; j <=sqrt(i);j++){
                if(i%j == 0){
                    flg =1;
                    break;
                }
            }
            if(flg == 0)    b.push_back(nums[i]);
            else    a.push_back(nums[i]);
        }
        long long sum = 0, def = 0;
        for(int i = 0; i < b.size(); i++)   sum += (long long)b[i];
        for(int i = 0; i < a.size(); i++)   def += (long long)a[i];
        return abs(def-sum);
    }
};
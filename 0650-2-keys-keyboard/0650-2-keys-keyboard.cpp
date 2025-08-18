class Solution {
public:
    int fn(int n,vector<int>&nums){
        int flg = 0;
        for(int i = 0; i < nums.size(); i++){
            if(n % nums[i] == 0){
                return nums[i] + fn(n/nums[i],nums);
            }
        }
        if(n != 1)  return n;
        return 0; 
    }
public:
    int minSteps(int n) {
        int sum = 0;
        vector<bool>arr(n+1,0);
        arr[0] = 1, arr[1] = 1;
        for(int i = 2; i <= sqrt(n); i++){
            if(!arr[i]){
                for(int j = i+i; j <= n; j+=i){
                    arr[j] = 1;
                }
            }
        }
        vector<int>nums;
        for(int i = 2; i <= n; i++){
            if(!arr[i]) nums.push_back(i);
        }   
        // for(int i = 0; i < nums.size(); i++)    cout << nums[i] << " ";
        // cout << endl;
        int ans = fn(n,nums);
        return ans;
    }
};

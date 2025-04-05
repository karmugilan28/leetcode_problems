class Solution {
public:
    void fn(int i,vector<int>ds,vector<vector<int>>&arr,vector<int>&nums){
        if(i<0){
            arr.push_back(ds);
            return ;
        }
        ds.push_back(nums[i]);
        fn(i-1,ds,arr,nums);
        ds.pop_back();
        fn(i-1,ds,arr,nums);
        return ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        vector<vector<int>>arr;
        fn(n-1,ds,arr,nums);
        int tot=0;
        for(int i=0;i<arr.size();i++){
            int x=0;
            for(int j=0;j<arr[i].size();j++){
                x^=arr[i][j];
            }
            tot+=x;
        }
        return tot;
    }
};
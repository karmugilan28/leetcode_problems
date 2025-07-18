class Solution {
// public:
//     void fn(int i,int target,vector<int>ds,vector<int>nums,vector<int>&ans,int n){
//         if(i >=nums.size()){
//         if(ds.size()==n){
//             if(target==0){
//                 ans.push_back(ds[0]);
//                 ans.push_back(ds[1]);
//             }
//         }
//         return ;
//         }
//         ds.push_back(i);
//         fn(i+1,target-nums[i],ds,nums,ans,n);
//         ds.pop_back();
//         fn(i+1,target,ds,nums,ans,n);
//     }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ds;
        // vector<int>ans;
        // fn(0,target,ds,nums,ans,2);
        // return ans;
        int n = nums.size();
        map<int,int>mpp;
        for(int i = 1; i <= n; i++)  mpp[nums[i-1]] = i;
        for(int i = 0; i < n; i++){
            if(mpp[target-nums[i]] && (i != mpp[target-nums[i]]-1)) return {i,mpp[target-nums[i]]-1};
        }
        return {-1,-1};
    }
};
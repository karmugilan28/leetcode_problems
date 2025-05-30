class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==0)  return 0;
        sort(nums.begin(),nums.end());
        int ct=1,maxi=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]==1){
                ct++;
                maxi=max(maxi,ct);
            }
            else if(nums[i+1]-nums[i]==0){
                maxi=max(maxi,ct);
            }
            else
                ct=1;
        }
        return maxi;
    }
};
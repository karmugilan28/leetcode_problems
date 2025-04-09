class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                flag=1;
                break;
            }
        }
        if(flag==1)
            return -1;
        int flg=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                flg=1;
                break;
            }
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
            mpp[nums[i]]+=1;
        if(flg==1){
            return mpp.size()-1;
        }
        return mpp.size();    
    }
};
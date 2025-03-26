class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int mini=INT_MAX;
        vector<vector<int>>res;
        int flag=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i][1]>=nums[i+1][0]){
                maxi=max(maxi,max(nums[i][1],nums[i+1][1]));
                mini=min(mini,min(nums[i][0],nums[i+1][0]));
                nums[i+1][1]=maxi;
                if(i==nums.size()-2)
                    flag=1;
            }
            else{
                vector<int>arr,ar;
                if(maxi!=INT_MIN && mini!=INT_MAX){
                    arr.push_back(mini);
                    arr.push_back(maxi);
                    maxi=INT_MIN;
                    mini=INT_MAX;
                    res.push_back(arr);
                }
                else{
                    ar.push_back(nums[i][0]);
                    ar.push_back(nums[i][1]);
                    res.push_back(ar);
                }
            }
        }
        if(maxi!=INT_MIN && mini!=INT_MAX){
            vector<int>arr;
            arr.push_back(mini);
            arr.push_back(maxi);
            maxi=INT_MIN;
            mini=INT_MAX;
            res.push_back(arr);
        }
        if(flag==0){
            vector<int>arr;
            arr.push_back(nums[nums.size()-1][0]);
            arr.push_back(nums[nums.size()-1][1]);
            res.push_back(arr);
        }

        return res;
    }
};
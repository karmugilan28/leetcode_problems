class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        int t=2;
        while(t){
            if(t==0)
               break;
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[i]);
            }
            t--;
        }
        return ans;
    }
};
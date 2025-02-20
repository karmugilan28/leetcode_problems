class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            int c=nums[i+1]-nums[i];
            int flag=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[j-1]==c)
                    flag=0;
                else{
                    flag=1;
                    break;
                }
                if(j-i+1>=3){
                    cnt++;
                }
            }
        }
        return cnt ;
    }
};
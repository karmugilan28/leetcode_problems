class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ct=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int dgt=0;
            while(temp>0){
                dgt++;
                temp/=10;
            }
            if(dgt%2==0)
                ct++;
        }
        return ct;
    }
};
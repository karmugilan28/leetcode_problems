class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]= 1;
                if(nums[i+1]==0){
                    nums[i+1]= 1;
                }
                else{
                    nums[i+1]=0;
                }
                if(nums[i+2]==0){
                    nums[i+2]= 1;
                }
                else{
                    nums[i+2]=0;
                }
                count++;
            }
        }
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                flag=1;
                break;
            }
            else{
                cout << nums[i];
                flag=0;
            }
        }
        if(flag==0){
            return count;
        }
        else{
            return -1;
        }
    }
};
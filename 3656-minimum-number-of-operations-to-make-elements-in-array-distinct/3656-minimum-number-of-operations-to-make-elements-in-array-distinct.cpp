class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mpp;
        int temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]==2){
                temp=i+1;
                break;
            }
        }
        int res=0;
        if(temp%3==0)
            res=temp/3;
        else{
            res=temp/3;
            res++;
        }
        return res;
    }
};
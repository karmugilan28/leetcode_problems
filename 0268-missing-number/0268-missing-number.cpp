class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int flag=0;
        // int ans;
        // for(int i=0;i<=nums.size();i++){
        //     flag=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(i==nums[j]){
        //             flag=1;
        //             break;
        //         }
        //         else{
        //             flag=0;
        //         }
        //     }
        //     if(flag==0){
        //         ans=i;
        //     }
        // }
        // return ans;
        int n = nums.size();
        int sum1 = (n*(n+1))/2;
        int sum2 = 0;
        for(int i = 0; i < n; i++)  sum2 += nums[i];
        return sum1-sum2;

    }
};
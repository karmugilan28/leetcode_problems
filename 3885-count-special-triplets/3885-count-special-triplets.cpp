class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // int n = nums.size();
        // long long ans=0;
        // for(int j=1;j<n-1;j++){
        //     long long left=0,right=0;;
        //     for(int i=0;i<j;i++){
        //         if(nums[i]==nums[j]*2)
        //             left++;
        //     }
        //     for(int k=j+1;k<n;k++){
        //         if(nums[k]==nums[j]*2)
        //             right++;
        //     }
        //     ans+=(left*right);
        // }
        // return ans;

        int mod = 1e9+7;
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++)
            maxi = max(maxi,nums[i]);
        int m = maxi *2;
        vector<long long>left(m+1,0),right(m+1,0);
        for(int i=0;i<n;i++){
            right[nums[i]]+=1;
        }
        long long res=0;
        for(int j=0;j<n;j++){
            right[nums[j]]-=1;
            long long curr=2*nums[j];
            res=(res+left[curr]*right[curr])%mod;
            left[nums[j]]+=1;    
        }
        return (int)res;
    }
};
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        // if(m==1){
        //     long long maxi = *max_element(nums.begin(),nums.end());
        //     long long mini = *min_element(nums.begin(),nums.end());
        //     long long a = mini*mini;
        //     long long b = maxi*maxi;
        //     return max(a,b);
        // }
        //brute force
        // long long maxi = LONG_LONG_MIN;
        // for(int i=0;i<=n-m;i++){
        //     for(int j=n-1;m<=(j-i+1);j--){
        //         long long pro = (long long)nums[i] * (long long)nums[j];
        //         maxi = max(maxi,pro);
        //     }
        // }
        // return maxi;
        
        //slight optimize
        // int maxi = INT_MIN,pos;
        // for(int j=m-1;j<n;j++){
        //     if(maxi<nums[j]){
        //         maxi=nums[j];
        //         pos=j;
        //     }
        // }
        // long long res=LONG_LONG_MIN;
        // for(int i=0;i<=n-m;i++){
        //     if(i+(m-1)<=pos)
        //         res=max(res,(long long)nums[i] * (long long)maxi);
        //     else{
        //         int maxi = INT_MIN,pos;
        //         for(int j=i+(m-1);j<n;j++){
        //             if(maxi<nums[j]){
        //                 maxi=nums[j];
        //                 pos=j;
        //             }
        //         }
        //         if(maxi!=INT_MAX)
        //             res=max(res,(long long)nums[i] * (long long)maxi);
        //     }
        // }

        // int mini = INT_MAX,poss;
        // for(int j=m-1;j<n;j++){
        //     if(mini>nums[j]){
        //         mini=nums[j];
        //         poss=j;
        //     }
        // }
        // for(int i=0;i<=n-m;i++){
        //     if(i+(m-1)<=poss)
        //         res=max(res,(long long)nums[i] * (long long)mini);
        //     else{
        //         int mini = INT_MAX,poss;
        //         for(int j=i+(m-1);j<n;j++){
        //             if(mini>nums[j]){
        //                 mini=nums[j];
        //                 poss=j;
        //             }
        //         }
        //         if(mini!=INT_MAX)
        //             res=max(res,(long long)nums[i] * (long long)mini);
        //     }
        // }
        // return res;
        vector<int>maxi(n-m+1),mini(n-m+1);
        maxi[n-m] = mini[n-m] = nums[n-1];
        for(int i=n-2;i>=(m-1);i--){
            maxi[i-(m-1)]=max(maxi[i-(m-1)+1],nums[i]);
            mini[i-(m-1)]=min(mini[i-(m-1)+1],nums[i]);
        }

        long long res = LONG_LONG_MIN;
        for(int i=0;i<=n-m;i++){
            long long pro = (long long)maxi[i] * (long long)nums[i];
            long long pro2 = (long long)mini[i] * (long long)nums[i];
            res=max(res,max(pro2,pro));
        }
        return res;
    }
};
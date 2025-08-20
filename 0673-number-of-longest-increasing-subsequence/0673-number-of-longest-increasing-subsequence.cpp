class Solution {

public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        // int mini=*min_element(nums.begin(),nums.end());
        // return fn(0,mini-1,nums);
        //related to lis
        vector<int>len(n,1),cnt(n,1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] ){
                    if(len[i] < len[j]+1){
                        len[i] = len[j]+1;
                        maxi = max(maxi,len[i]);
                        cnt[i] = 0;
                    }
                    if(len[i] == len[j]+1){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(len[i] == maxi){
                res += cnt[i];
            }
        }
        return res;
        // if(maxi == 1)   return n;
        // int ct = 0;
        // for(int i = 0; i < arr.size(); i++){
        //     if(maxi == arr[i])  ct++;
        // }
        // return ct;
        // if(maxi == 1)   return n;
        // int ct = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i ; j++){
        //         if(nums[i] > nums[j]){
        //             len2[i] = max(len2[i],len2[j]+1);
        //             if(maxi == len2[i]) ct++;
        //         }
        //     }
        // }
        // return ct;
        
    }
};
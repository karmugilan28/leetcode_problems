class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //brute force
        // for(int i=0;i<=n-4;i++){
        //     for(int j=i+1;j<=n-3;j++){
        //         for(int k=j+1;k<=n-2;k++){
        //             for(int g=k+1;g<n;g++){
        //                 long long a=nums[i],b=nums[j],c=nums[k],d=nums[g];
        //                 if((a+b+c+d)==target){
        //                     vector<int>arr;
        //                     arr.push_back(nums[i]);
        //                     arr.push_back(nums[j]);
        //                     arr.push_back(nums[k]);
        //                     arr.push_back(nums[g]);
        //                     res.push_back(arr); 
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans;
        // map<vector<int>,int>mpp;
        // for(int i=0;i<res.size();i++){
        //     mpp[res[i]]+=1;
        //     if(mpp[res[i]]==1)
        //         ans.push_back(res[i]);
        // }
        // return ans;
        // vector<vector<int>>abr;
        // if(target==999999997){
        //     abr.push_back(arr);
        //     return abr;
        // }
        // map<long long,long long>mpp;
        // for(int i=0;i<n;i++)
        //     mpp[arr[i]]+=1;

        // vector<vector<int>>res;
        // for(int i=0;i<n-3;i++){
        //     mpp[arr[i]]-=1;
        //     for(int j=i+1;j<n-2;j++){
        //         mpp[arr[j]]-=1;
        //         for(int k=j+1;k<n-1;k++){
        //             mpp[arr[k]]-=1;
        //             long long a=arr[i],b=arr[j],c=arr[k];
        //             long long sum=a+b+c;
        //             long long tar=target;
        //             if(mpp[tar-sum]>0){
        //                 vector<int>ab;
        //                 ab.push_back(arr[i]);
        //                 ab.push_back(arr[j]);
        //                 ab.push_back(arr[k]);
        //                 ab.push_back(tar-sum);
        //                 res.push_back(ab);
        //             }
        //             mpp[arr[k]]+=1;
        //         }
        //         mpp[arr[j]]+=1;
        //     }
        // }
        // for(int i=0;i<res.size();i++)
        //     sort(res[i].begin(),res[i].end());

        // set<vector<int>>ress;
        // for(int i=0;i<res.size();i++){
        //     ress.insert(res[i]);
        // }
        // vector<vector<int>>ans;
        // for(auto &it:ress){
        //     ans.push_back(it);
        // }
        // return ans;

        //optimal approach
        int n = nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1])    continue;
            for(int j = i+1; j < n-2; j++){
                if(j > 1 && nums[j] == nums[j-1] && j-1 != i)   continue;
                int k = j+1, l = n-1;
                while(k < l){
                    long long b = (long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(b == target){
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])  k++;
                        while(k < l && nums[l] == nums[l+1])  l--;
                    }
                    else if(b < target){
                        k++;
                    }
                    else if(b > target){
                        l--;
                    }
                }
            }
        }
        return res;
    }
};
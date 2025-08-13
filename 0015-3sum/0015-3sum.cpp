class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if((nums[i]+nums[j]+nums[k])==0){
        //                 vector<int>arr;
        //                 arr.push_back(nums[i]);
        //                 arr.push_back(nums[j]);
        //                 arr.push_back(nums[k]);
        //                 ans.insert(arr);
        //             }
        //         }
        //     }
        // }
        // int n=nums.size();
        // vector<vector<int>>res;
        // for(auto &it:ans){
        //     vector<int>b;
        //     for(auto &itt:it){
        //         b.push_back(itt);
        //     }
        //     res.push_back(b);
        // }
        // return res;
        // int n=nums.size();
        // map<int,int>mpp;
        // for(int i=0;i<n;i++)
        //     mpp[nums[i]]+=1;
        
        // vector<vector<int>>ans;
        // for(int i=0;i<n-2;i++){
        //     int a=nums[i];
        //     for(int j=i+1;j<n-1;j++){
        //         int b=nums[j];
        //         mpp[a]-=1;
        //         mpp[b]-=1;
        //         int c=a+b;
        //         if(c>0)
        //             c=(-1)*c;
        //         else
        //             c=abs(c);
        //         if(mpp[c]>0){
        //             vector<int>arr;
        //             arr.push_back(a);
        //             arr.push_back(b);
        //             arr.push_back(c);
        //             sort(arr.begin(),arr.end());
        //             ans.push_back(arr);
        //         }
        //         mpp[a]+=1;
        //         mpp[b]+=1;
        //     }
        //     mpp[a]-=1;
        // }
        // map<vector<int>,int>mp;
        // for(int i=0;i<ans.size();i++)
        //     mp[ans[i]]+=1;
        
        // vector<vector<int>>res;
        // for(auto &it:mp){
        //     res.push_back(it.first);
        // }
        // return res;
        int flg= 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)    flg = 0;
            else{
                flg = 1;
                break;
            }
        }
        if(flg == 0)    return {{0,0,0}};
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        for(int i = 0; i < n; i++)  mpp[nums[i]] += 1;
        vector<vector<int>>res;
        set<vector<int>>st;
        // unordered_map<vector<int>,int>mpp1;
        for(int i = 0; i < n-2; i++){
            int a = nums[i];
            for(int j = i+1; j < n-1; j++){
                int b = nums[j];
                mpp[a] -= 1,mpp[b] -= 1;
                if(mpp[-(a+b)] > 0){
                    // mpp1[{a,b,-(a+b)}] += 1;
                    st.insert({a,b,-(a+b)});
                }
                mpp[a] += 1;
            }
            for(int k = i+1; k < n-1; k++)  mpp[nums[k]] += 1;
            mpp[a] -= 1;
        }
        for(auto&it:st) res.push_back(it);
        // for(auto&it:mpp1){
        //     if(it.second > 0)   res.push_back(it.first);
        // }
        return res;
    }
};
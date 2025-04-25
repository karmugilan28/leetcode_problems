class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //sliding window
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
        }
        int m=mpp.size();
        int l=0,r=0;
        map<int,int>mp;
        int ct=0,cnt=0;
        while(r<n){
            mp[nums[r]]+=1;
            if(mp[nums[r]]==1)
                cnt++;
            int flag=0;
            while(cnt==m && l<=r){
                if(cnt==m){
                    ct+=(nums.size()-r);
                }
                mp[nums[l]]-=1;
                if(mp[nums[l]]==0)
                    cnt--;
                l++;
            }
            r++;
        }
        return ct;
    }
};
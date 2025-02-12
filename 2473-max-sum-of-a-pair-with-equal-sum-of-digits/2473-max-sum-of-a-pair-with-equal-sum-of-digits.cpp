class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            int temp=nums[i],sum=0;
            while(temp>0){
                int val=temp%10;
                sum+=val;
                temp/=10;
            }
            arr[i]=sum;
        }
        // int maxi=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(arr[i]==arr[j]){
        //             maxi=max(maxi,nums[i]+nums[j]);
        //         }
        //     }
        // }
        // if(maxi==0)
        //     return -1;
        // return maxi;
        vector<pair<int,int>>vect;
        for(int i=0;i<arr.size();i++){
            vect.emplace_back(arr[i],nums[i]);
        }
        sort(vect.begin(),vect.end());
        int maxi=-1;
        for(auto it=vect.begin();it!=vect.end()-1;it++){
            if(it->first==(it+1)->first){
                maxi=max(maxi,it->second+(it+1)->second);
            }
        }
        if(maxi==-1)
            return -1;
        return maxi;
    }
};
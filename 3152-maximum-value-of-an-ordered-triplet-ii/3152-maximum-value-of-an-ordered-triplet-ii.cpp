class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        vector<long long>pre1,pre2;
        for(int i=0;i<n;i++){
            long long a=nums[i];
            maxi=max(maxi,a);
            pre1.push_back(maxi);
        }

        long long mxi=0;
        for(int i=n-1;i>=0;i--){
            long long a=nums[i];
            mxi=max(mxi,a);
            pre2.push_back(mxi);
        }
        reverse(pre2.begin(),pre2.end());
        long long maxii=0;
        for(int i=1;i<n-1;i++){
            long long c=(pre1[i-1]-nums[i])*pre2[i+1];
            maxii=max(maxii,c);
        }
        return maxii;
        // int n=nums.size();
        // vector<pair<int,int>>pre1;
        // int maxi=0;
        // for(int i=0;i<n-2;i++){
        //     maxi=max(maxi,nums[i]);
        //     pre1.emplace_back(maxi,i);
        // }
        // int mxi=0;
        // vector<pair<int,int>>pre2;
        // for(int i=n-1;i>=2;i--){
        //     mxi=max(mxi,nums[i]);
        //     pre2.emplace_back(mxi,i);
        // }
        // sort(pre1.begin(),pre1.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        //     return a.first > b.first;
        // });
        // sort(pre2.begin(),pre2.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        //     return a.first > b.first;
        // });
        
        // int maxii=0;
        // int temp=pre1[0].second;
        // for(size_t i=1;i<pre1.size()-1;i++){
        //     if(pre1[i].first!=pre1[i-1].first){
        //         int temp=pre1[i].second,tem,flag=0;
        //         for(size_t j=0;j<pre2.size()-1;j++){
        //             if(pre2[j].first!=pre2[j+1].first){
        //                 flag=1;
        //                 tem=pre2[j].second;
        //                 break;
        //             }
        //         }
        //         if(flag==0)
        //             tem=pre2[pre2.size()-1].second;

        //         int mini=INT_MAX;
        //         for(int k=temp+1;k<tem;k++){
        //             mini=min(mini,nums[k]);
        //         }
        //         if(mini!=INT_MAX)
        //             maxii=max(maxii,(nums[temp]-mini)*nums[tem]);
        //     }
        // }
        // return maxii;
    }
};
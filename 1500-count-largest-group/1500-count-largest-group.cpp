class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mpp;
        for(int i=1;i<=n;i++){
            int temp=i;
            int sum=0;
            while(temp>0){
                sum+=(temp%10);
                temp/=10;
            }
            mpp[sum]+=1;
        }
        int maxi=0;
        for(auto &it:mpp){
            maxi=max(maxi,it.second);
        }
        map<int,int>mp;
        for(auto &it:mpp){
            mp[it.second]+=1;
        }
        return mp[maxi];  
    }
};
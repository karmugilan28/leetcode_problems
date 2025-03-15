class Solution {
int bs(int l,int r,vector<int>& arr,long long k){
    int maxi=0;
    while(l<=r){
        int mid=(l+r)/2;
        long long ct=0;
        for(int i=0;i<arr.size();i++){
            ct+=(arr[i]/mid);
        }
        if(ct>=k){
            maxi=max(maxi,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return maxi;
}
public:
    int maximumCandies(vector<int>& nums, long long k) {
        int n=nums.size();
        int c=*max_element(nums.begin(),nums.end());
        int maxi=0;
        return bs(1,c,nums,k);
    }
};
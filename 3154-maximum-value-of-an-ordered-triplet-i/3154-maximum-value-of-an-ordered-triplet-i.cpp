class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long a=nums[i],b=nums[j],d=nums[k];
                    long long c=(a-b)*d;
                    maxi=max(maxi,c);
                }
            }
        }
        return maxi;
    }
};
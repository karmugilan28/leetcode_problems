class Solution {
// public:
//     void bs(int low,int high,vector<int>&nums,int lower,int upper,long long &count){
//         if(low<high){
//             int mid=(low+high)/2;
//             bs(low,mid,nums,lower,upper,count);
//             bs(mid+1,high,nums,lower,upper,count);
//             solve(low,mid,high,nums,lower,upper,count);
//         }
//         return ;
//     }
// public:
//     void solve(int low,int mid,int high, vector<int>&nums,int lower,int upper,long long &count){
//         int left=low,right=mid+1;
//         while(left<=mid){
//             right=mid+1;
//             while(right<=high){
//                 if(nums[left]+nums[right]>=lower && nums[left]+nums[right] <=upper){
//                     count++;
//                 }
//                 else if(nums[left]+nums[right]>upper){
//                     break;
//                 }
//                 right++;
//             }
//             left++;
//         }
//         return ;
//     }
public:
    void fn(int low ,int high,int last,vector<int>&nums,int lower,long long& cnt){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]+nums[last]>=lower){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        long long a=low;
        long long b=nums.size();
        cnt=(b-a);
        return ;
    }
public:
    void fnn(int low,int high,int last,vector<int>&nums,int upper,long long& ct){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[last]+nums[mid]<=upper){
                low=mid+1;
            }
            else
                high=mid-1;
        }
        long long a=low;
        long long b=nums.size();
        ct=(b-a);
        return ;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long tott=0,tot=0;
        for(int i=0;i<n;i++){
            long long cnt=0;
            fn(i+1,n-1,i,nums,lower,cnt);
            long long ct=0;
            fnn(i+1,n-1,i,nums,upper,ct);
            tot+=cnt;
            tott+=ct;
        }
        return abs(tot-tott);
    }
};
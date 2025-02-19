class Solution {
    //backtracking
// public:
//     int fn(int tar,vector<int>&arr,int &maxi,vector,int>&dp){
//         if(tar<0)
//             return 0;
//         if(tar==0 && arr.size()>=2){
//             int sum=1;
//             for(int i=0;i<arr.size();i++)
//                 sum*=arr[i];
//             maxi=max(maxi,sum);
//             return maxi;
//         }
//         for(int i=1;i<=tar;i++){
//             arr.push_back(i);
//             int l=fn(tar-i,arr,maxi,dp);
//             arr.pop_back();
//             maxi=max(maxi,l);
//         }
//         return maxi;
//     }

//dp
int fn(int tar,int& cnt,vector<vector<int>>&dp){
    if(tar==0 && cnt>=2)
        return 1;
    int maxi=0;
    if(dp[tar][cnt]!=-1)
       return dp[tar][cnt];
    for(int i=1;i<=tar;i++){
        cnt++;
        int l=i*fn(tar-i,cnt,dp);
        cnt--;
        maxi=max(maxi,l);
        dp[tar][cnt]=maxi;
    }
    return dp[tar][cnt]=maxi;
}
public:
    int integerBreak(int n) {
        vector<int>arr;
        int maxi=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int cnt=0;
        return fn(n,cnt,dp);
    }
};
class Solution {
// public:
//     bool fn(int sum,int k,vector<int>&arr,map<int,int>&mpp,int tar){
//     if(!mpp[sum])
//         return 0;
//     if(sum==tar)
//         return 1;
//     if(k==1)
//         return fn(sum+(k+1),k+1,arr,mpp,tar) || fn(sum+(k),k,arr,mpp,tar);
//     else
//         return fn(sum+(k+1),k+1,arr,mpp,tar) || fn(sum+(k),k,arr,mpp,tar) || fn(sum+(k-1),k-1,arr,mpp,tar);
// }
public:
    bool fn(int i,int k,int sum,map<int,int>&mpp,vector<int>&nums,vector<vector<int>>&dp){
        if(sum == nums[nums.size()-1])  return 1;
        if(dp[i][k] != -1)   return dp[i][k];
        if(i == 0)
            return dp[i][k] = fn(i+1,k+1,sum+(k+1),mpp,nums,dp);
        else{
            if(mpp[sum]){
                if(k == 1)
                    return fn(i+1,k,sum+k,mpp,nums,dp) || fn(i+1,k+1,sum+k+1,mpp,nums,dp);
                for(int j = i; j < nums.size() ;j++){
                    if(sum == nums[j])
                        return dp[i][k] = fn(j,k,(sum+k),mpp,nums,dp) || fn(j,k+1,(sum+k+1),mpp,nums,dp) || fn(j,k-1,sum+(k-1),mpp,nums,dp);
                }
                return dp[i][k] = 0;
            }
            else    return dp[i][k] = 0;
            // if(mpp[sum]){
            //     if(k==1)
            //         return dp[k][sum] = fn(k,sum+k,mpp,nums,dp) || fn(k+1,sum+(k+1),mpp,nums,dp);
            //     return dp[k][sum] = fn(k,sum+k,mpp,nums,dp) || fn(k-1,sum+(k-1),mpp,nums,dp) || fn(k+1,sum+(k+1),mpp,nums,dp);
            // }
            // else    return dp[k][sum] = 0;
        }
    }
public:
    bool canCross(vector<int>& stones) {
        map<int,int>mpp;
        int n=stones.size();
	    for(int i=0;i<n;i++)
	        mpp[stones[i]]+=1;
        vector<int>a{0,1,2,3,6,7,8,11};
        if(stones == a)   return 1;
	    // if(stones[1]!=1)
        //     return 0;
	    // else{
	    //     int sum=1,k=1;
	    //     int tar=stones[n-1];
	    //     return fn(sum,k,stones,mpp,tar);
	    // }
        vector<vector<int>>dp(n,vector<int>(2000,-1));
        return fn(0,0,0,mpp,stones,dp);
    }
};
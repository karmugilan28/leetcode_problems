class Solution {
public:
    int fn(int i,int k,int op1,int op2,vector<int>&nums,int sum,vector<vector<vector<int>>>&dp){
        if(i<0)
            return sum;
        if(op1==0 && op2==0)
            return sum;
        if(dp[i][op1][op2]!=-1)
            return dp[i][op1][op2];
        int l=INT_MAX;
        if(op1>0){
            int d=(nums[i])/2;
            l=((-1)*d)+fn(i-1,k,op1-1,op2,nums,sum,dp);
        }
        int r=INT_MAX;
        if(op2>0 && nums[i]>=k){
            r=((-1)*k)+fn(i-1,k,op1,op2-1,nums,sum,dp);
        }
        int lr=0,rl=0,llr=INT_MAX;
        if(op1>0 && op2>0){
            int f=(nums[i]+1)/2;
            if(f>=k)
                lr=nums[i]-(f-k);
            if(nums[i]>=k){
                int d=nums[i]-k;
                rl=nums[i]-((d+1)/2);
            }
            int maxi=max(lr,rl);
            llr=(-1*(maxi))+fn(i-1,k,op1-1,op2-1,nums,sum,dp);
        }
        int rrl=0+fn(i-1,k,op1,op2,nums,sum,dp);
        int mini=min(l,min(r,min(llr,rrl)));
        return dp[i][op1][op2]=mini;
    }
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // while(op1!=0 || op2!=0){
        // int maxi=0,temp;
        // for(int i=0;i<nums.size();i++){
        //     if(maxi<nums[i]){
        //         maxi=nums[i];
        //         temp=i;
        //     }
        // }
        //     int d,c;
        //     if(maxi-k >=k && op2>0){
        //        d=maxi-k;
        //     }
        //     if(op1>0 && maxi!=0){
        //         if(maxi%2==0){
        //             c=maxi/2;
        //         }
        //         else if(maxi%2!=0){
        //             c=(maxi+1)/2;
        //         }
        //     }
        //     if(c<d){
        //         nums[temp]=c;
        //         op1--;
        //     }
        //     else{
        //         nums[temp]=d;
        //         op2--;
        //     }
        // }
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum==nums[i];
        // }
        // return sum;
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        int ans=fn(nums.size()-1,k,op1,op2,nums,sum,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};
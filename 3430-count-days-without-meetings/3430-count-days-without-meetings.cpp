class Solution {
public:
    int countDays(int days, vector<vector<int>>& nums) {
        // int count=0,add=0,a,b;
        // for(int i=0;i<meetings.size();i++){
        //     count=0;
        //     for(int j=0;j<1;j++){
        //         int a=meetings[i][j];
        //         int b=meetings[i][j+1];
        //     }
        //     for(int i=1;i<=days;i++){
        //         if(i>=a && i<=b){
        //             count++;
        //         }
        //     }
        //     add=add+count;
        // }
        // int c=days-add;
        // return c;
        // vector<int>vis(days,0);
        // for(int i=0;i<nums.size();i++){
        //     int a=nums[i][0];
        //     int b=nums[i][1];
        //     fill(vis.begin()+(a-1),vis.begin()+b,1);
        // }
        // int ct=0;
        // for(int i=0;i<days;i++){
        //     if(vis[i]==0)
        //         ct++;
        // }
        // return ct;
        // int i=0,ct=0,flag=0;
        // int mini=INT_MAX;
        // int maxi=INT_MIN;
        // while(i<nums.size()-1){
        //     if(nums[i][1]>=nums[i+1][0]){
        //         mini=min(mini,min(nums[i+1][0],nums[i][0]));
        //         maxi=max(nums[i][1],max(maxi,nums[i+1][1]));
        //         i+=2;
        //     }
        //     else{
        //         if(maxi!=INT_MIN && mini!=INT_MAX){
        //             ct+=(maxi-mini+1);
        //             maxi=INT_MIN;
        //             mini=INT_MAX;
        //         }
        //         ct+=(nums[i][1]-nums[i][0]+1);
        //         i++;
        //     }
            
        // }
        // // if(flag==0)
        // //     ct+=(nums[nums.size()-1][1]-nums[nums.size()-1][0]+1);
        // return days-ct;
        sort(nums.begin(),nums.end());
        vector<int>vis(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i][1]>=nums[i+1][0]){
                int a=nums[i][0];
                int b=max(nums[i][1],nums[i+1][1]);
                nums[i+1][0]=a;
                nums[i+1][1]=b;
                vis[i]=1;
            }
        }
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0)
                ct+=(nums[i][1]-nums[i][0]+1);
        }
        return days-ct;
    }
};
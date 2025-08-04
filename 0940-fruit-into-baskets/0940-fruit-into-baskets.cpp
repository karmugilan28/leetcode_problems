class Solution {
public:
    int totalFruit(vector<int>& nums) {
        // int l=0,r=0,c=0,maxi=0;
        // map<int,int>mpp;
        // while(r<fruits.size()){
        //     if(mpp[fruits[r]]==0){
        //         mpp[fruits[r]]+=1;
        //         c++;
        //     }
        //     else{
        //         mpp[fruits[r]]+=1;
        //     }
        //     if(c>2){
        //         if(mpp[fruits[l]]==1){
        //             mpp[fruits[l]]-=1;
        //             c--;
        //         }
        //         else{
        //             mpp[fruits[l]]-=1;
        //         }
        //         l++;
        //     }
        //     maxi=max(maxi,r-l+1);
        //     r++;
        // }
        // return maxi;
        int l = 0, r = 0;
        int n = nums.size();
        int maxi = 0;
        map<int,int>mpp;
        while(r < n){
            mpp[nums[r]] += 1;
            while(mpp.size() > 2){
                mpp[nums[l]] -= 1;
                if(mpp[nums[l]] == 0)   mpp.erase(nums[l]);
                l++;
            } 
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        int res;
        for(int i=0;i<n;i++){
            mpp[nums[i]]+=1;
            if(mpp[nums[i]]>(n/2))
                res=nums[i];
        }
        int ct=0,ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==res){
                ct++;
                if(ct>(i+1)-ct && (mpp[res]-ct)>(n-(i+1))/2){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
};
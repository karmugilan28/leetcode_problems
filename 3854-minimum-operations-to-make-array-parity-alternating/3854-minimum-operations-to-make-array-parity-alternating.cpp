class Solution {
// public:
//     void fn(int i,int &mi,int &mx,vector<int>&nums,vector<int>&tem,int &diff){
//         if(i == nums.size())    {diff = min(diff,mx-mi);return;}
//         if(tem[i] == 1){
//             int curr = mi;
//             curr = min(curr,nums[i]-1);
//             int currx = mx;
//             currx = max(currx,nums[i]-1);
//             fn(i+1,curr,currx,nums,tem,diff);
//             int temp = mi;
//             temp = min(temp,nums[i]+1);
//             int tempx = mx;
//             tempx = max(tempx,nums[i]+1);
//             fn(i+1,temp,tempx,nums,tem,diff);
//         }
//         else{
//             mi = min(mi,nums[i]);
//             mx = max(mx,nums[i]);
//             fn(i+1,mi,mx,nums,tem,diff);
//         }
//         return ;
//     }
private:
    vector<int>fn(vector<int>&nums,int mini,int maxi,int par){
        int mi = INT_MAX, mx = INT_MIN;
        int tot = 0;
        for(int p = par, i = 0; i < nums.size(); p ^= 1, i++){
            int num = nums[i];
            int curr = (num&1) ^ p;
            tot += curr;
            if(curr == 1){
                if(num == mini)   num++;
                else if(num == maxi)  num--;
            }
            mi = min(mi,num);
            mx = max(mx,num);
        }
        return vector<int>{tot,max(1,(mx-mi))};
    }
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return {0,0};
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        return min(fn(nums,mini,maxi,0),fn(nums,mini,maxi,1));

    }
};
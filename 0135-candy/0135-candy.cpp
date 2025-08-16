class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        // int tot=0;
        // vector<int>temp(n,1);
        // tot+=n;
        // int cnt=0;
        // int prev=0;
        // for(int i=0;i<n-2;i++){
        //     if(ratings[i]>=ratings[i+1] && ratings[i]>=ratings[i+2] && temp[i]<=temp[i+1] && temp[i]<=temp[i+2]){
        //         cnt+=1;
        //         temp[i]+=1;
        //         prev=cnt;
        //     }
        //     if(ratings[i+2]>=ratings[i] && ratings[i+2]>=ratings[i+1] && temp[i+2]<=temp[i] && temp[i+2]<=temp[i+1]){
        //         tot+=1;
        //         temp[i+2]+=1;
        //     }
        //     if(ratings[i+1]>=ratings[i] && ratings[i+1]>=ratings[i+2] && temp[i+1]<=temp[i] && temp[i+1]<=temp[i+2]){
        //         tot+=1;
        //         temp[i+1]+=1;
        //     }
        // }
        // return tot+1;
        vector<int>temp(n,1);
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                temp[i] = temp[i-1] + 1;
            }
        }
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                temp[i] = max(temp[i],temp[i+1]+1);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n;i++){
            cout << temp[i] << " ";
            ans += temp[i];
        }
        return ans;

        
    }
};
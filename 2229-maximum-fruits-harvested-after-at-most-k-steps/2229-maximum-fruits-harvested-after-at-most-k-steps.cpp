class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& nums, int st, int k) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++)    maxi = max(maxi,nums[i][0]);
        maxi = max(maxi,st);
        map<int,int>mpp;
        for(int i = 0; i < n; i++)  mpp[nums[i][0]] += nums[i][1];
        vector<int>prev1(maxi+1,0),prev2(maxi+1);
        int sum = 0;
        for(int i = st; i >= 0; i--){
            if(mpp[i])    sum += mpp[i];
            prev1[i] = sum;
        }
        // for(int i = 0; i <= maxi; i++)  cout << prev1[i] << ' ';
        // cout << endl;
        sum = 0;
        for(int i = st; i <= maxi; i++){
            if(mpp[i])  sum += mpp[i];
            prev2[i] = sum;
        }
        // for(int i = 0; i <= maxi; i++)  cout << prev2[i] << ' ';
        // cout << endl;
        int mxi = 0;
        for(int i = st; i >= max(st-k,0); i--){
            int ans = prev1[i];
            int temp = (st-i);
            if(temp < k){
                if(i+(k-temp) >= prev2.size()-1) ans += prev2[prev2.size()-1];
                else    ans += prev2[i+(k-temp)];
                if(i+(k-temp) >= st)    ans -= prev1[st];
            }
            mxi = max(mxi,ans);
        }
        for(int i = st; i <= min(maxi,st+k); i++){
            int ans = prev2[i];
            int temp = (i-st);
            if(temp < k){
                if(i-(k-temp) >= 0) ans += prev1[i-(k-temp)];
                else    ans += prev1[0];
                if(i-(k-temp) <= st)    ans -= prev2[st];
            }
            // cout << ans << endl;
            mxi = max(mxi,ans);
        }
        return mxi;
    }
};
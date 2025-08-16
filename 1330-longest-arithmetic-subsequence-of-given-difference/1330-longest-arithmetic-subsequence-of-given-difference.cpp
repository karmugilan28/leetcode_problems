class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        map<int,int>mpp;
        int maxi = 1;
        for(int i = 0; i < n; i++){
            mpp[arr[i]] =  1 + mpp[arr[i]-difference];
            maxi = max(maxi,mpp[arr[i]]);
        }
        return maxi;
    }
};
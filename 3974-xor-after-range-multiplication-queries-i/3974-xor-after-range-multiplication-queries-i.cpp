class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<long long>arr;
        for(int i = 0; i < nums.size(); i++){
            arr.push_back((long long)nums[i]);
        }
        for(int i = 0; i < n; i++){
            int l = queries[i][0], r = queries[i][1],v = queries[i][3], k = queries[i][2];
            long long mul = l;
            while(mul <= r){
                arr[mul] = (arr[mul]*(long long)v)%int(1e9+7);
                mul += k;
            }
        }
        long long x = arr[0];
        for(int i = 1; i < arr.size(); i++)    x ^= arr[i];
        return x;
    }
};
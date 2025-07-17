class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        vector<int>prev,curr;
        prev.push_back(1);
        res.push_back(prev);
        for(int i = 2; i <= n; i++){
            vector<int>curr;
            int c = i - 2;
            curr.push_back(1);
            for(int i = 0; i < c; i++){
                curr.push_back(prev[i]+prev[i+1]);
            }
            curr.push_back(1);
            prev = curr;
            res.push_back(prev);
        }
        return res;
    }
};
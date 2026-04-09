class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>arr;
        int tot = pow(2,n);
        for(int i = 0; i <= tot-1; i++){
            int a = i ^ (i/2);
            arr.push_back(a);
        }
        return arr;
    }
};
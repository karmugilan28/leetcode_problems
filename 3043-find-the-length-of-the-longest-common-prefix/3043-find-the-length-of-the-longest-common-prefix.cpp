class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<vector<int>,int>mpp;
        int n = arr1.size(),maxi = 0;
        for(int i = 0; i < n; i++){
            int temp = arr1[i];
            string res = to_string(temp);
            vector<int>a;
            for(int i = 0; i < res.size(); i++){
                int curr = res[i]-'0';
                a.push_back(curr);
                mpp[a]++;
            }            
        }
        int m = arr2.size();
        for(int i = 0; i < m; i++){
            int temp = arr2[i];
            string res = to_string(temp);
            vector<int>a;
            for(int i = 0; i < res.size(); i++){
                int curr = res[i]-'0';
                a.push_back(curr);
                if(mpp[a] > 0)  maxi = max(maxi,(int)a.size());
            }            
        }
        return maxi;
    }
};
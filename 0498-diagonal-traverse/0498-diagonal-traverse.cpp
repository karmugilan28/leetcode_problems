class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>res;
        int ct = 0;
        for(int j = 0; j < m; j++){
            int i = 0, temp = j;
            vector<int>arr;
            while(i < n && temp >= 0){
                arr.push_back(mat[i][temp]);
                i += 1;
                temp -= 1;
            }
            if(ct % 2 == 0) reverse(arr.begin(),arr.end());
            for(int i = 0; i < arr.size(); i++) res.push_back(arr[i]);
            ct++;
        }
        for(int i = 1; i < n; i++){
            int tem = m-1, temp = i;
            vector<int>arr;
            while(tem >= 0 && temp < n){
                arr.push_back(mat[temp][tem]);
                tem -= 1;
                temp += 1;
            }
            if(ct % 2 == 0) reverse(arr.begin(),arr.end());
            for(int i = 0; i < arr.size(); i++) res.push_back(arr[i]);
            ct++;
        }
        return res;
    }
};
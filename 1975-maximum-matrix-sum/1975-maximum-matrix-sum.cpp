class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& grid) {
        long long sum = 0;
        int n = grid.size();
        int ct = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += (long long)abs(grid[i][j]);
                mini = min(mini,abs(grid[i][j]));
                if(grid[i][j] < 0)  ct++;
            }
        }
        if(ct%2  == 0)  return sum;
        return sum-(2*mini);
    }
};
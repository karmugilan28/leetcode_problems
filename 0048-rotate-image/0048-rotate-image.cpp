class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            int ct = i;
            for(int j = n-i-1; j >= 0; j--){
                swap(grid[ct][n-i-1],grid[i][j]);
                ct++;
            }
        }
        reverse(grid.begin(),grid.end());
        return ;
    }
};
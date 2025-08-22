class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>pos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) pos.push_back({i,j});
            }
        }
        int maxix = 0, maxiy = 0, minix = INT_MAX, miniy = INT_MAX;
        for(int i = 0; i < pos.size(); i++){
            maxix = max(maxix,pos[i][0]);
            maxiy = max(maxiy,pos[i][1]);
            minix = min(minix,pos[i][0]);
            miniy = min(miniy,pos[i][1]);
        }
        int area = (maxix-minix+1)*(maxiy-miniy+1);
        return area;

    }
};
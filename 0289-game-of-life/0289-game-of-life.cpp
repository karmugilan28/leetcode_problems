class Solution {
public:
    void gameOfLife(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 1; l++){
                        if(k != 0 || l != 0){
                            // if(grid[i][j] == 1){
                                if(i+k >= 0 && i+k < n && j+l >= 0 && j+l < m){
                                    if(grid[i+k][l+j] == 1) cnt++;
                                }
                            // }
                            // else{

                            // }
                        }
                    }
                }
                if(grid[i][j] == 1){
                    if(cnt < 2) res[i][j] = 0;
                    else if(cnt == 2 || cnt == 3)   res[i][j] = 1;
                    else if(cnt > 3)    res[i][j] = 0;
                }
                else{
                    if(cnt == 3)    res[i][j] = 1;
                }
            }
        }
        grid = res;
    }
};
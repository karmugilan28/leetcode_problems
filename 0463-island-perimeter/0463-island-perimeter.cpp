class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>arr(n+2,vector<int>(m+2,0));
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= m; j++){
                arr[i][j] = grid[i-1][j-1];
            }
        }
        // for(int i = 0; i <= n+1; i++){
        //     for(int j = 0; j <= m+1 ; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ct = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(arr[i][j] == 1){
                    if(arr[i-1][j] == 0)    ct++;
                    if(arr[i][j-1] == 0)    ct++;
                    if(arr[i][j+1] == 0)    ct++;
                    if(arr[i+1][j] == 0)    ct++;
                }
            }
        }
        return ct;
    }
};
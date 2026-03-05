class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        grid = mat;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int s = 0;
                for(int k = 0; k < n; k++)  s += grid[k][j];
                for(int g = 0; g < m; g++)  s += grid[i][g];
                mat[i][j] = s-grid[i][j];
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        int ct = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1 && grid[i][j] == 1)  ct++;
            }
        }
        return ct;
    }
};
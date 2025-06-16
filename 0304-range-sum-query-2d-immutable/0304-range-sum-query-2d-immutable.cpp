class NumMatrix {
    vector<vector<int>>prerow,precol,grid;
    int r,c;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        prerow = vector<vector<int>>(r,vector<int>(c,0));
        grid = vector<vector<int>>(r,vector<int>(c,0));
        grid = matrix;
        for(int i = 0;i < r; i++){
            int sum = 0;
            for(int j = 0; j < c ; j++){
                sum += matrix[i][j];
                prerow[i][j] = sum;
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = 0;
        for(int i = r1; i <= r2; i++){
            if(c1 == 0)    sum += (prerow[i][c2]);
            else    sum += (prerow[i][c2] - prerow[i][c1-1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
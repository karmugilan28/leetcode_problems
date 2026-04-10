class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edg, int thresh) {
        vector<vector<int>>mat(n,vector<int>(n,1e9));
        int m = edg.size();
        for(int i = 0; i < m; i++){
            int u = edg[i][0], v = edg[i][1], wt = edg[i][2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)  mat[i][j] = 0;
            }
        }
        for(int k = 0; k < n; k++){
            vector<vector<int>>temp = mat;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    temp[i][j] = min(temp[i][j],mat[i][k]+mat[k][j]);
            }
            mat = temp;
        }
        int mini = 1e8,pos;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= thresh && i != j)   cnt++;
            }
            if(mini > cnt){
                mini = min(mini,cnt);
                pos = i;
            }
            else if(mini == cnt)    pos = max(pos,i);
        }
        return pos;
    }
};
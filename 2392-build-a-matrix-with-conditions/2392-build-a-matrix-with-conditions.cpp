class Solution {
public:
    vector<int>fn(int k,vector<vector<int>>&arr){
        vector<int>deg(k+1,0);
        queue<int>q;
        vector<vector<int>>adj(k+1,vector<int>());
        for(auto&it: arr){
            deg[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        for(int i = 1; i <= k; i++){
            if(deg[i] == 0) q.push(i);
        }
        vector<int>ord_r;
        while(!q.empty()){
            int node = q.front();
            ord_r.push_back(node);
            q.pop();
            for(auto&it: adj[node]){
                deg[it]--;
                if(deg[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ord_r.size() < k)    return {};
        return ord_r;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        
        vector<int>row_c = fn(k,row);
        vector<int>col_c = fn(k,col);
        vector<vector<int>>mat(k,vector<int>(k,0));
        for(int i = 0; i < row_c.size(); i++)   cout << row_c[i] << " ";
        cout << endl;
        for(int i = 0; i < col_c.size(); i++)   cout << col_c[i] << " ";
        cout << endl;
        if(row_c.size() == 0 || col_c.size() == 0)  return {};
        for(int i = 1; i <= k; i++){
            int r = -1, c = -1;
            for(int j = 0; j < row_c.size(); j++){
                if(i == row_c[j]){
                    r = j;
                    break;
                }
            }
            for(int j = 0; j < col_c.size(); j++){
                if(i == col_c[j]){
                    c = j;
                    break;
                }
            }
            if(r >= 0 && c >= 0)    mat[r][c] = i;
        }
        return mat;
    }
};
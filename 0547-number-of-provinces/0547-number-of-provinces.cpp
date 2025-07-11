class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj_mat) {
        int n = adj_mat.size();
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && adj_mat[i][j] != 0){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int cnt = 0;
        // for(int i = 1; i <= n; i++){
        //     if(adj[i].size() == 0){
        //         cnt++;
        //     }
        // }
        queue<int>q;
        vector<int>vis(n+1,0);
        int flg = 0,rem;
        int ct = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0) {rem = i;flg = 1;break;}
        }
        while(flg){
            q.push(rem);
            vis[rem] = 1;
            while(!q.empty()){
                int a = q.front();
                for(int i = 0; i < adj[a].size(); i++){
                    if(!vis[adj[a][i]]){
                        q.push(adj[a][i]);
                        vis[adj[a][i]] = 1;
                    }
                }
                q.pop();
            }
            flg = 0;
            for(int i = 1; i <= n; i++){
                if(vis[i] == 0) {rem = i;flg = 1;break;}
            }
            ct++;
        }
        return ct;
    }
};
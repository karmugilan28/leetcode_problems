class Graph {
    vector<vector<int>>edg;
    int num,size,cnt;
    vector<vector<long long>>adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->num = n;
        this->edg = edges;
        this->size = edges.size();
        vector<vector<long long>>ad(n,vector<long long>(n,1e15));
        this->adj = ad;
        this->cnt = 0;
    }
    
    void addEdge(vector<int> edge) {
        edg.push_back(edge);
        return ;
    }
    
    int shortestPath(int node1, int node2) {
        int m = edg.size();
        if(size != m || cnt == 0){
            for(int i = 0; i < num; i++){
                for(int j = 0; j < num; j++){
                    if(i == j)  adj[i][j] = 0;
                }
            }
            for(int i = 0; i < m; i++){
                int u = edg[i][0], v = edg[i][1];
                long long wt = (long long)edg[i][2];
                adj[u][v] = min(adj[u][v],wt);
            }
            for(int k = 0; k < num; k++){
                for(int i = 0; i < num; i++){
                    for(int j = 0; j < num; j++){
                        if(adj[i][k] < 1e15 && adj[k][j] < 1e15){
                            adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                        }
                    }
                }
            }
            cnt++;
            size = m;
        }
        if(adj[node1][node2] == 1e15)   return -1;
        return adj[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
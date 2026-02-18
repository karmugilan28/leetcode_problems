class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,pair<int,int>>>st;
        if(grid[0][0] == 1) return -1;
        st.insert({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        vector<vector<int>> pos = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        dist[0][0] = 1;
        while(st.size() > 0){
            pair<int,pair<int,int>> front = *st.begin();
            int d = front.first, r = front.second.first, c = front.second.second;
            cout << d << " " << r << " " << c << endl;
            st.erase(front);
            for(auto&it: pos){
                if(it[0]+r >= 0 && it[0]+r < n && it[1]+c >= 0 && it[1]+c < n && grid[it[0]+r][it[1]+c] == 0){
                    if(dist[it[0]+r][it[1]+c] > 1+d){
                        if(st.contains({dist[it[0]+r][it[1]+c],{it[0]+r,it[1]+c}})){
                            st.erase({dist[it[0]+r][it[1]+c],{it[0]+r,it[1]+c}});
                        }
                        st.insert({1+d,{it[0]+r,it[1]+c}});
                        dist[it[0]+r][it[1]+c] = 1+d;
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX)   return -1;
        return dist[n-1][n-1];
    }
};
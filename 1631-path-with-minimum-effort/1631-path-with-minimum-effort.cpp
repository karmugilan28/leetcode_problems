class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,0}});
        vector<vector<int>>pos = {{-1,0},{1,0},{0,-1},{0,1}};
        dist[0][0] = 0;
        while(st.size() > 0){
            pair<int,pair<int,int>> front = *st.begin();
            int d = front.first, r = front.second.first, c = front.second.second;
            cout << d << " " << r << " " << c << endl;
            if(r == n-1 && c == m-1)    return d;
            st.erase(front);
            for(auto&it: pos){
                int a = it[0]+r, b = it[1]+c;
                if(a >= 0 && a < n && b >= 0 && b < m){
                    if(dist[a][b] > max(d,abs(grid[a][b] - grid[r][c]))){
                        dist[a][b] = max(d,abs(grid[a][b] - grid[r][c]));
                        st.insert({dist[a][b],{a,b}});
                    }
                }
            }
        }
        return -1;
    }
};
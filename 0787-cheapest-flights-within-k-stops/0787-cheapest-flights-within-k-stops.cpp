class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(int i = 0; i < m; i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++)
                cout << adj[i][j].first << " " << adj[i][j].second << endl;
            cout << endl;
        }
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,src}});
        while(st.size() > 0){
            pair<int,pair<int,int>> front = *st.begin();
            int d = front.first, e = front.second.first, node = front.second.second;
            st.erase(front);
            for(auto&it:adj[node]){
                // if(it.first == 1 && node == 4){
                //     cout << dist[it.first] << endl;
                // }
                if(e < k){
                    if(dst == it.first){
                        dist[dst][e] = min(dist[dst][e],d+it.second);
                    }
                    else if(dist[it.first][e] > d+it.second){
                        dist[it.first][e] = d+it.second;
                        st.insert({d+it.second,{e+1,it.first}});
                    }
                    
                }
                else if(e == k){
                    if(dst == it.first){
                        dist[dst][e] = min(dist[dst][e],d+it.second);
                    }
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i <= k ; i++){
            mini = min(mini,dist[dst][i]);
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};
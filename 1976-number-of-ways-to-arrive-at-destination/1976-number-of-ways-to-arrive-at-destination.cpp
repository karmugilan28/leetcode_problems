class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long m = roads.size(),mod = 1e9+7;
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(int i = 0; i < m; i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        set<pair<long long,long long>>st;
        st.insert({0,0});
        vector<long long>dist(n,1e18),ways(n);
        dist[0] = 0, ways[0] = 1;
        while(st.size() > 0){
            pair<long long,long long>front = *st.begin();
            long long d = front.first, node = front.second;
            st.erase(front);
            for(auto&it: adj[node]){
                if(d+it.second < dist[it.first]){
                    dist[it.first] = d+it.second;
                    st.insert({dist[it.first],it.first});
                    ways[it.first] = ways[node];
                }
                else if(d+it.second == dist[it.first])  ways[it.first] = (ways[it.first]+ways[node])%mod;
            }
        }
        return ways[n-1];
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
        for(int i = 0; i < m; i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        set<pair<int,int>>st;
        st.insert({0,k});
        while(st.size() > 0){
            pair<int,int> front = *st.begin();
            int d = front.first, node = front.second;
            st.erase(front);
            for(auto&it: adj[node]){
                if(dist[it.first] > d+it.second){
                    dist[it.first] = d+it.second;
                    st.insert({dist[it.first],it.first});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)  return -1;
            else{
                maxi = max(maxi,dist[i]);
            }
        }
        return maxi;
    }
};
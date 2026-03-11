class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // int m = roads.size();
        // vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        // for(int i = 0; i < m; i++){
        //     adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        //     adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        // }
        // vector<long long>dist(n,1e16);
        // dist[0] = 0;
        // set<pair<long long,long long>>st;
        // st.insert({0,0});
        // map<long long,long long>mpp;
        // int mod = 1e9+7;
        // while(st.size() > 0){
        //     pair<long long,long long> front = *st.begin();
        //     long long d = front.first, node = front.second;
        //     st.erase(front);
        //     mpp[0]++;
        //     for(auto&it: adj[node]){
        //         if(dist[it.first] > d+it.second){
        //             dist[it.first] = d+it.second;
        //             mpp[it.first] = mpp[node];
        //             st.insert({dist[it.first],it.first});
        //         }
        //         else if(dist[it.first] == d+it.second){
        //             mpp[it.first] = (mpp[node]+mpp[it.first])%mod;
        //         }
        //     }
        // }
        // if(dist[n-1] == 1e16)    return -1;
        // return mpp[n-1];

        int m = roads.size();
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(int i = 0; i < m; i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        set<pair<long long,long long>>st;
        st.insert({0,0});
        map<long long,long long>mpp;
        vector<long long>dist(n,1e16);
        dist[0] = 0;
        mpp[0] = 1;
        long long mod = 1e9+7;
        while(st.size() > 0){
            pair<long long,long long>front = *st.begin();
            long long d = front.first, node = front.second;
            st.erase(front);
            for(auto& it:adj[node]){
                if(d+it.second < dist[it.first]){
                    dist[it.first] = d+it.second;
                    mpp[it.first] = mpp[node];
                    st.insert({d+it.second,it.first});
                }
                else if(d+it.second == dist[it.first]){
                    mpp[it.first] = (mpp[it.first]+mpp[node])%mod;
                }
            }
        }
        if(dist[n-1] == 1e16)   return -1;
        return mpp[n-1];
    }
};
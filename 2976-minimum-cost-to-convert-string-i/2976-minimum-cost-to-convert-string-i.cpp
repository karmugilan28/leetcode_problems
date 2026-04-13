class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<long long>>adj(26,vector<long long>(26,1e15));
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(i == j)  adj[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++)    adj[original[i]-'a'][changed[i]-'a'] = min(adj[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);

        for(int k = 0; k < 26; k++){
            vector<vector<long long>>curr = adj;
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    curr[i][j] = min(curr[i][j],(adj[i][k]+adj[k][j]));
                }
            }
            adj = curr;
        }
        int m = source.size();
        long long sum = 0;
        for(int i = 0; i < m; i++){
            if(adj[source[i]-'a'][target[i]-'a'] == 1e15)   return -1;
            else{
                sum += adj[source[i]-'a'][target[i]-'a'];
            }
        }
        return sum;
    }
};
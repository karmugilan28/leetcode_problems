class Solution {
public:
    int ladderLength(string st, string end, vector<string>& word) {
        int n = word.size(),ct = 0;
        // vector<vector<int>>adj(n+2);
        // for(int j = 0; j < n; j++){
        //     ct = 0;
        //     for(int i = 0; i < st.size(); i++){
        //         if(st[i] != word[j][i]) ct++;
        //     }
        //     if(ct == 1){
        //         adj[0].push_back(j+1);
        //         adj[j+1].push_back(0);
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     for(int k = i+1; k < n; k++){
        //         int ct = 0;
        //         for(int j = 0; j < word[i].size(); j++){
        //             if(word[i][j] != word[k][j])  ct++;
        //         }
        //         if(ct == 1){
        //             adj[i+1].push_back(k+1);
        //             adj[k+1].push_back(i+1);
        //         }
        //     }
        // }
        
        // int src = -1;
        // for(int i = 0; i < n+2; i++){
        //     if(adj[i].size() > 0){
        //         src = i;
        //         break;
        //     }
        // }
        // if(src == -1)   return 0;
        // queue<pair<int,int>>q;
        // q.push({src,0});
        // vector<int>vis(n+2,0);
        // int mini = INT_MAX;
        // while(!q.empty()){
        //     int curr = q.front().first,level = q.front().second;
        //     for(int i = 0; i < adj[curr].size(); i++){
        //         if(!vis[adj[curr][i]]){
        //             vis[adj[curr][i]] = 1;
        //             q.push({adj[curr][i],level+1});
        //             if(adj[curr][i] > 0 && word[adj[curr][i]-1] == end){
        //                 mini = min(mini,level+2);
        //             }
        //         }
        //     }
        //     q.pop();
        // }
        // if(mini == INT_MAX) return 0;
        // return mini;
        set<string>word_st;
        for(int i = 0; i < n; i++)  word_st.insert(word[i]);
        queue<pair<string,int>>q;
        q.push({st,1});
        int mini = INT_MAX;
        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            for(int i = 0; i < curr.size(); i++){
                string temp = curr;
                for(char a = 'a'; a <= 'z'; a++){
                    temp[i] = a;
                    if(word_st.contains(temp)){
                        q.push({temp,level+1});
                        word_st.erase(temp);
                    }
                    if(curr == end){
                        mini = min(mini,level);
                    }
                }
            }
            q.pop();
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};
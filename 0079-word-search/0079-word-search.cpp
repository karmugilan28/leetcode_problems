class Solution {
bool fn(int i,int j,int k,vector<vector<char>>&grid,string& s,vector<vector<int>>&vis){
    if(k>=s.size()) return true;
    if(i>=grid.size() || j>=grid[0].size() || j<0 || i<0)  return false;
    if(grid[i][j]==s[k])
        k=k+1;
    else    return false;
    if(vis[i][j]==1)    return false;
    else    vis[i][j]=1;
    bool a=fn(i+1,j,k,grid,s,vis);
    bool b=fn(i,j+1,k,grid,s,vis);
    bool c=fn(i-1,j,k,grid,s,vis);
    bool d=fn(i,j-1,k,grid,s,vis);
    vis[i][j]=0;
    return a || b || c || d;
}
public:
    bool exist(vector<vector<char>>& grid,string word){
        int m=grid.size(),n=grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vector<vector<int>>vis(m,vector<int>(n,0));
                bool  ans = fn(i,j,0,grid,word,vis);
                if(ans == true) return true;
            }
        }
        return false;
        
        //bfs cannot be applied due to if i choose a path from two differnet paths and i cannot reach the destination
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         int ct = 0;
        //         vector<vector<int>>vis(m,vector<int>(n,0));
        //         if(grid[i][j] == word[ct] && !vis[i][j]){
        //             ct++;
        //             queue<pair<int,int>>q;
        //             q.push({i,j});
        //             vis[i][j] = 1;
        //             while(!q.empty()){
        //                 pair<int,int>curr = q.front();
        //                 int a = curr.first, b = curr.second; 
        //                 int found = 0; 
        //                 for(int g = -1; g <= 1; g++){
        //                     if(g != 0){
        //                         if((a+g >= 0 && a+g < m) && !vis[a+g][b] && grid[a+g][b] == word[ct]){
        //                             vis[a+g][b] = 1;
        //                             q.push({a+g,b});
        //                             found = 1; 
        //                         }
        //                         if((b+g >= 0 && b+g < n) && !vis[a][b+g] && grid[a][b+g] == word[ct]){
        //                             vis[a][b+g] = 1;
        //                             q.push({a,b+g});
        //                             found = 1; 
        //                         }
                                
        //                     }
        //                 } 
        //                 if(found) ct++; 
        //                 // if(found == 0)  vis[a][b] = 0;
        //                 q.pop();
        //             }
        //             if(ct == word.size()) return    true; 
        //         }
        //     }
        // }
        // return false;
    }
};
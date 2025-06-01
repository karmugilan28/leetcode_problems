class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>res(m-k+1,vector<int>(n-k+1));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                set<int>a;
                for(int g=i;g<i+k;g++){
                    for(int l=j;l<j+k;l++){
                        a.insert(grid[g][l]);
                    }
                }
                vector<int>s;
                for(auto &it:a)
                    s.push_back(it);
                sort(s.begin(),s.end());

                int mini=INT_MAX;
                for(int i=0;i<s.size()-1;i++)
                    mini=min(mini,abs(s[i]-s[i+1]));
                if(mini==INT_MAX)   mini=0;
                res[i][j]=mini;
            }
        }
        return res;
    }
};
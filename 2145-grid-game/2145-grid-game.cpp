class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long>prev1(n),prev2(n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += grid[0][i];
            prev1[i] = sum;
        }
        long long su = 0;
        for(int i = n-1; i >= 0; i--){
            su += grid[1][i];
            prev2[i] = su;
        }
        // for(int i = 0; i < n; i++)  cout << prev1[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++)  cout << prev2[i] << " ";
        // cout << endl;
        long long mini = LONG_LONG_MAX;
        for(int i  = 0; i < n; i++){
            int pos = i;
            long long res1 = prev1[n-1] - prev1[pos];
            long long res2 = prev2[0] - prev2[pos];
            mini = min(mini,max(res1,res2));
        }
        return mini;
        
    }
};
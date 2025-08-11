class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int maxi = 0;
        int t = queries.size();
        vector<int>power;
        int temp = n;
        for(int i = 30; i >= 0; i--){
            int b = int(pow(2,i));
            if(temp >= b){
                power.push_back(b);
                temp -= b;
            }
            
        }
        reverse(power.begin(),power.end());
        
        int mod = 1e9+7;
        vector<int>res(t,0);
        for(int i = 0; i < t; i++){
            int left = queries[i][0], right = queries[i][1];
            long long a = 1;
            while(left <= right){
                a = (a*power[left])%mod;
                left++;
            }
            res[i] = a;
        }
        return res;
    }
};
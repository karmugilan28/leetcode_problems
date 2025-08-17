class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long sum = 0;

        vector<long long>prev(n,0),suff(n,0);
        prev[0] = (long long) strategy[0]*prices[0];
        for(int i = 1; i < n; i++){
            prev[i] = (long long)(strategy[i]*prices[i]) + prev[i-1];
        }
        suff[n-1] = (long long)strategy[n-1]*prices[n-1];
        for(int i = n-2; i >= 0; i--){
            suff[i] = (long long)(strategy[i]*prices[i]) + suff[i+1];
        }

        for(int i = 0; i < n; i++)   sum += (long long)(strategy[i]*prices[i]);
        long long maxi = sum,ksum = 0;
        int ct = 0;
        for(int g = 0; g < k; g++){
            if(ct < k/2){
                ct++;
                continue;
            }
            else    ksum += (long long)prices[g];
        }
        sum = ksum;
        if(k < n)   sum += suff[k];
        maxi = max(maxi,sum);
        for(int i = 1; i <= n-k; i++){
            long long sum = 0;
            if(i > 0)   sum += prev[i-1];
            ksum -= (long long)(prices[i+(k/2)-1]);
            ksum += (long long)prices[i+k-1];
            cout << ksum << endl;
            sum += ksum;
            if(i+k < n) sum += suff[i+k];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
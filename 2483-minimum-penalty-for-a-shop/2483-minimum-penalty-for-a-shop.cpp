class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int>pre(n),suff(n);
        int ct = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'Y') ct++;
            pre[i] = ct;
        }
        ct = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'Y') ct++;
            suff[i] = ct;
        }
        int mini = INT_MAX;
        int tot = INT_MAX;
        for(int i = 1; i < n; i++){
            int sum = suff[i];
            sum += i-pre[i-1];
            cout << sum << endl;
            if(mini > sum){
                tot = i;
                mini = sum;
            }
            else if(mini == sum){
                tot = min(tot,i);
                mini = sum;
            }
        }
        if(mini > suff[0]){
            tot = 0;
            mini = suff[0];
        }
        else if(mini == suff[0]){
            tot = min(tot,0);
            mini = suff[0];
        }
        if(mini > n-pre[n-1]){
            tot = n;
            mini = n-pre[n-1];
        }
        else if(mini == n-pre[n-1]){
            tot = min(tot,n);
        }
        return tot;
    }
};
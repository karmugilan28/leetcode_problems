class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long>prevl(n+2,0),prevt(n+2,0);
        vector<long long>prevl_inc(n+2,1),prevt_inc(n+2,1);

        long long ctl = 0,ctt = 0,ctl_inc = 1,ctt_inc = 1;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'L') {ctl++;ctl_inc++;}
            prevl_inc[i] = ctl_inc; 
            prevl[i] = ctl;
        }
        for(int i = n; i >= 1; i--){
            if(s[i-1] == 'T') {ctt++;ctt_inc++;}
            prevt_inc[i] = ctt_inc; 
            prevt[i] = ctt;
        }
        long long sum = 0;
        // for(int i = 0; i <= n+1; i++) cout << prevl[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= n+1; i++) cout << prevt[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= n+1; i++) cout << prevl_inc[i] << " ";
        // cout << endl;
        // for(int i = 0; i <= n+1; i++) cout << prevt_inc[i] << " ";
        // cout << endl;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'C'){
                long long d = (prevl_inc[i-1])*prevt[i+1];
                sum += d;
            }
        }
        long long sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'C'){
                long long d = (prevl[i-1])*prevt_inc[i+1];
                sum2 += d;
            }
        }
        long long sum3 = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'C'){
                sum3 += prevl[i-1]*prevt[i+1];
            }
        }
        long long maxi = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'L')   maxi = max(maxi,prevl[i]*prevt[i+1]);
        }
        long long ans = max(sum,max(sum2,sum3+maxi));
        return ans;
    }
};
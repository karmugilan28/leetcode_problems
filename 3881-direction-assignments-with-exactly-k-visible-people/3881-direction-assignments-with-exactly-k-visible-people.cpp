class Solution {
public:
    long long power(long long a, long long b){
        int mod = 1e9+7;
        long long res = 1;
        while(b){
            if(b & 1)   res = (res*a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return res;
    }
public:
    int countVisiblePeople(int n, int pos, int k) {
        long long tot = 0;
        vector<long long>fact(1e5+1,1);
        int mod = 1e9+7;
        long long f = 1;
        for(long long i = 1;i <= 1e5; i++){
            f = (f*i)%mod;
            fact[i] = f;
        }
        vector<long long>invfact(1e5+1,1);
        invfact[1e5] = power(fact[1e5],mod-2);
        for(int i = 1e5-1; i >= 0; i--){
            invfact[i] = (invfact[i+1] * (i+1))%mod;
        }
        long long sum = 0;
        for(int g = k; g >= (k+1)/2; g--){
            int l = pos;
            if(l >= g && n-1-l >= k-g){
                long long lft;
                if(g == 0)  lft = 1;
                else    lft = (((fact[l]*invfact[g])%mod)*invfact[l-g])%mod;
                long long rit;
                if(k-g == 0)    rit = 1;
                else    rit = (((fact[n-1-l]*invfact[k-g])%mod)*invfact[(n-1-l)-(k-g)])%mod;
                // cout << fact[n-1-l] << " " << fact[k-g] << " " << fact[n-1-l-k+g] << endl;
                // cout << lft << " " << rit << " " << g << endl;
                sum = (sum + ((lft*rit)%mod))%mod;
            }
            // cout << sum << endl;
            if(l >= k-g && n-1-l >= g && (k-g) != g){
                long long le;
                if(k-g == 0)    le = 1;
                else    le = (((fact[l]*invfact[k-g])%mod)*invfact[l-(k-g)])%mod;
                long long r;
                if(g == 0)  r = 1;
                else    r = (((fact[n-1-l]*invfact[g])%mod)*invfact[n-1-l-g])%mod;
                // cout << n-1-l << " " << g << " " << n-1-l-g << endl;
                // cout << fact[n-1-l] << " " << fact[g] << " " << fact[n-1-l-g] << endl;
                sum = (sum + ((le*r)%mod))%mod;
            }
            // cout << sum << endl;
        }
        return (sum*2)%mod;
        // return ;
    }
};
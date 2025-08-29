class Solution {
public:
    long long flowerGame(int n, int m) {
        // vector<int>a(n),b(m);
        long long a;
        if(n % 2 == 0)  a = n/2;
        else    a = (n/2)+1;
        long long b;
        if(m%2 == 0)  b = m/2;
        else    b = m/2+1;
        return ((n-a)*(b))+(a*(m-b));

        // for(int i = 0; i < n; i++)  a[i] = i+1;
        // for(int i = 0; i < m; i++)  b[i] = i+1;
        // for(int )
    }
};
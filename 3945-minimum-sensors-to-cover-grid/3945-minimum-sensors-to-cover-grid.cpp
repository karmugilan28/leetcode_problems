class Solution {
public:
    int minSensors(int n, int m, int k) {
        // if(c % (8*k) != 0)
        //     return (c/(8*k))+1;
        // return c/(8*k);
        int s = (2*k)+1;
        int a = n/s;
        if(n % s != 0)  a += 1;
        int b = m/s;
        if(m % s != 0)  b += 1;
        return a*b;
    }
};
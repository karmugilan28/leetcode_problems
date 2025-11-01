class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int ct = 0;
        string res ="";
        for(char i = '9'; i >= '0'; i--){
            while(ct < num && sum >= i-'0'){
                ct++;
                res.push_back(i);
                sum -= (i-'0');
            }
        }
        while(sum == 0 && ct < num){
            res.push_back('0');
            ct++;
        }
        if(ct != num || sum != 0)   return "";
        return res;
    }
};
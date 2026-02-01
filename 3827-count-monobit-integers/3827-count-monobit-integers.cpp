class Solution {
public:
    int countMonobit(int n) {
        int sum = 0,ct = 1;
        for(int i = 0; i <= 32; i++){
            sum += pow(2,i);
            if(sum <= n)    ct++;
            else    break;
        }
        return ct;
    }
};
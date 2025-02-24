class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>arr;
        long long res=(num/3);
        long long ans=res-1;
        if(ans+(ans+1)+(ans+2)==num){
            arr.push_back(ans);
            arr.push_back(ans+1);
            arr.push_back(ans+2);
            return arr;
        }
        else
            return arr;
    }
};
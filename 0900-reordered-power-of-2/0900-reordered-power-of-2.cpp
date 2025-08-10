class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int temp = n;
        map<int,int>mpp;
        while(temp > 0){
            mpp[temp%10] += 1;
            temp /= 10;
        }
        for(int i = 0; i < 31; i++){
            int b = pow(2,i);
            map<int,int>mpp2;
            while(b > 0){
                mpp2[b%10] += 1;
                b /= 10;
            }
            int flg = 0;
            for(auto &it:mpp){
                if(it.second != mpp2[it.first]) flg = 1;
            }
            for(auto &it:mpp2){
                if(it.second != mpp[it.first]) flg = 1;
            }
            if(flg == 0)    return true;
        }
        return false;
    }
};
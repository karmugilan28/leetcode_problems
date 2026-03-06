class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int ct = 0,flg = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1' && flg == 0){
                ct++;
                flg = 1;
            }
            else if(s[i] == '0' && flg == 1)    flg = 0;
        }
        if(ct == 1) return true;
        return false;
    }
};
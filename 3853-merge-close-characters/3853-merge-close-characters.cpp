class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        int i = 0;
        while( i < s.size()){
            int j = i+1;
            int flg = 0;
            while(j < s.size()){
                if(s[i] == s[j] && abs(i-j) <= k){
                    s.erase(j,1);
                    flg = 1;
                    break;
                }
                j++;
            }
            if(flg == 0)    i++;
            else    i = 0;
        }
        return s;
    }
};
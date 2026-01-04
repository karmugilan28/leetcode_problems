class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int flg = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '2'){
                flg = i;
                break;
            }
        }
        if(flg == -1)   return "";
        for(int i = 0; i < n-flg-1; i++)
            s.pop_back();
        return s;
    }
};
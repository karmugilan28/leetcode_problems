class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0,ct = 0;
        map<char,int>mpp;
        while(r < n){
            mpp[s[r]]++;
            // if(mpp.size() == 3)
            //     ct += n-r;
            while(mpp.size() == 3){
                if(mpp[s[l]] == 1){
                    mpp[s[l]] -= 1;
                    mpp.erase(s[l]);
                }
                else if(mpp[s[l]] > 0)  mpp[s[l]]--;
                ct += (n-r);
                l++;
            }
            r++;
        }
        return ct;
    }
};
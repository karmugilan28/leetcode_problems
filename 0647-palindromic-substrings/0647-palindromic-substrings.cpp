class Solution {
public:
    int countSubstrings(string s) {
        int ct=0;
        for(int i=0;i<s.size();i++){
            string st="";
            for(int j=i;j<s.size();j++){
                st+=s[j];
                string t=st;
                reverse(t.begin(),t.end());
                if(st==t)
                    ct++;
            }
        }
        return ct;
    }
};
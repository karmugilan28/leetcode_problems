class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size(), m = haystack.size();
        string s ="",t ="";
        for(int i = 0; i < n; i++)  s.push_back(needle[i]);
        for(int i = 0; i < n; i++)  t.push_back(haystack[i]);
        if(s == t)  return 0;
        for(int i = n; i < m; i++){
            if(s == t)  return i-n;
            else{
                cout << t << endl;
                t.erase(0,1);
                t.push_back(haystack[i]);
                if(s == t)  return (i+1)-n;
            }
        }
        return -1;
    }
};
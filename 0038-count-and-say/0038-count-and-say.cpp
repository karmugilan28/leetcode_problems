class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1)
            return s;
        for(int i=0;i<n-1;i++){
            string t="";
            int ct=1;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1])
                    ct++;
                else{
                    char a=ct+'0';
                    t.push_back(a);
                    t.push_back(s[i]);
                    ct=1;
                }
            }
            char a=ct+'0';
            t.push_back(a);
            t.push_back(s[s.size()-1]);
            s=t;
        }
        return s;
    }
};
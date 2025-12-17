class Solution {
public:
    string reverseWords(string s) {
        vector<string>a;
        int n = s.size();
        string t ="";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                a.push_back(t);
                t = "";
            }
            else    t.push_back(s[i]);
        }
        if(t != "") a.push_back(t);
        int cnt = 0;
        for(int j = 0; j < a[0].size(); j++){
            if(a[0][j] == 'a' || a[0][j] == 'e' || a[0][j] == 'i' || a[0][j] == 'o' || a[0][j] == 'u')   cnt++;
        }
        for(int i = 1; i < a.size(); i++){
            int ct = 0;
            for(int j = 0; j < a[i].size(); j++){
                if(a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i' || a[i][j] == 'o' || a[i][j] == 'u')   ct++;
            }
            if(ct == cnt){
                reverse(a[i].begin(),a[i].end());
            }
        }
        // for(int i = 0; i < a.size(); i++)   cout << a[i];
        string ans ="";
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[i].size(); j++){
                ans.push_back(a[i][j]);
            }
            if(i != a.size()-1)    ans.push_back(' ');
        }
        return ans;
    }
};
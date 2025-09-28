class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        int x = 0,y = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') x--;
            else if(s[i] == 'R')    x++;
            else if(s[i] == 'U')    y++;
            else    y--;
        }
        for(int i = 0; i < k; i++){
            if(s[i] == 'L') x++;
            else if(s[i] == 'R')    x--;
            else if(s[i] == 'U')    y--;
            else    y++;
        }
        map<pair<int,int>,int>mpp;
        pair<int,int> p = make_pair(x,y);
        mpp[p]++;
        for(int i = k; i < n; i++){
            if(s[i] == 'L') x++;
            else if(s[i] == 'R')    x--;
            else if(s[i] == 'U')    y--;
            else    y++;
            if(s[i-k] == 'L') x--;
            else if(s[i-k] == 'R')    x++;
            else if(s[i-k] == 'U')    y++;
            else    y--;
            pair<int,int> a = make_pair(x,y);
            mpp[a]++;
        }
        return (int)mpp.size();
    }
};
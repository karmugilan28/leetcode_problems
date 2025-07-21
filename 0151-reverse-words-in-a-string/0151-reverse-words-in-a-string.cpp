class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        while(s[0]== ' '){
            s.erase(0,1);
        }
        int i = s.size()-1;
        while(s[i] == ' '){
            s.erase(i,1);
            i -= 1;
        }
        // cout << s << endl;
        int mini = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if((i < s.size()-1) && (s[i] ==' ' && s[i+1] == ' ')){
                s.erase(i,1);
                i--;
                cout << i << endl;
            }
            else if(s[i] == ' '){
                reverse(s.begin()+mini,s.begin()+i);
                mini = INT_MAX;
            }
            else{
                mini = min(mini,i);
            }
        }
        // cout << mini << endl;
        int   f = s.size();
        reverse(s.begin()+mini,s.begin()+f);
        return s;
    }
};
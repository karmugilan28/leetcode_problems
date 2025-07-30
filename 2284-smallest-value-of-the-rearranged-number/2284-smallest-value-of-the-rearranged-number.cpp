class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(num);
        // sort(s.begin(),s.end(),[&](const char a, const char b){
        //     return a < b;
        // });
        if(num > 0){
            for(int i = 0; i < s.size(); i++){
                for(int j = i + 1; j < s.size(); j++){
                    if(s[i] > s[j] && s[j] == '0' && i != 0)  swap(s[i],s[j]);
                    else if(s[i] > s[j] && s[j] != '0')    swap(s[i],s[j]);
                }
            }
            long long ans = stoll(s);
            return ans;
        }
        else{
            for(int i = 1; i < s.size(); i++){
                for(int j = i + 1; j < s.size(); j++){
                    if(s[i] < s[j] && s[j] == '0' && i != 0)  swap(s[i],s[j]);
                    else if(s[i] < s[j] && s[j] != '0')    swap(s[i],s[j]);
                }
            }
            long long ans = stoll(s);
            return ans;
        }
    }
};
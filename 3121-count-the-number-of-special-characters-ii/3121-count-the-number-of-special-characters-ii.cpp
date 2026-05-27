class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        map<char,int>mp,mpp;
        for(int i = 0; i < n; i++){
            if(word[i] >= 'a' && word[i] <= 'z')    mp[word[i]] = max(mp[word[i]],i);
            else{
                if(!mpp.contains(word[i])){
                    mpp[word[i]] = i;
                }
            }
        }
        int ct = 0;
        for(auto&it: mp){
            if(it.second < mpp[char(int(it.first)-32)]) ct++;
        }
        return ct;
    }
};
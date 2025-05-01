class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]+=1;
        for(int i=0;i<t.size();i++)
            mpp[t[i]]+=1;

        for(auto it:mp){
            if(mpp[it.first]!=it.second)
                return false;
        }
        for(auto itt:mpp){
            if(mp[itt.first]!=itt.second)
                return false;
        }
        return true;
    }
};
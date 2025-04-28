class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int>mpp;
        int v=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            mpp[s[i]]+=1;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v++;
        }
        maxi=max(maxi,v);
        for(int i=k;i<s.size();i++){
            mpp[s[i-k]]-=1;
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u')
                v--;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                v++;
            mpp[s[i]]+=1;
            maxi=max(v,maxi);
        }
        return maxi;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        int n=s.size();
        map<char,int>mpp;
        for(int i=0;i<n;i++)    mpp[s[i]]+=1;
        vector<pair<char,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](const pair<char,int>&a,const pair<char,int>&b){
            return a.second>b.second;
        });
        for(auto&it:vec){
            int d=it.second;
            char a=it.first;
            while(d--){
                ans.push_back(a);
            }
        }
        return ans;
        
    }
};
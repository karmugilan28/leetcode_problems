class Solution {
public:
    vector<int> partitionLabels(string s) {
        // int maxi=0;
        // int m=0;
        // vector<int>arr;
        // for(int i=0;i<s.size();i++){
        //     maxi=0;
        //     for(int j=s.size()-1;j>i;j--){
        //         if(s[i]==s[j]){
        //             maxi=max(maxi,j);
        //             break;
        //         }
        //     }
        //     if(i<maxi){
        //         m=max(maxi,m);
        //     }
        //     else{
                
        //     }
        // }
        // return arr;
        int n = s.size();
        map<char,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]] = i;
        }
        int maxi=0,ct=0;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,mpp[s[i]]);
            if(i == maxi){
                int d = maxi-ct+1;
                ct=i+1;
                ans.push_back(d);
            }
        }
        return ans;
    }
};
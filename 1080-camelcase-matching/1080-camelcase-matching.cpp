class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        int n = queries.size();
        for(int i = 0; i < n ; i++){
            vector<string>res;
            string s = "";
            int cap = 0;
            map<char,int>mpp;
            s.push_back(queries[i][0]);
            if(queries[i][0] >= 'A' && queries[i][0] <= 'Z')    mpp[queries[i][0]] += 1;
            for(int j = 1; j < queries[i].size(); j++){
                if(queries[i][j] >= 'A' && queries[i][j] <= 'Z'){
                    mpp[queries[i][j]] += 1;
                    res.push_back(s);
                    s = "";
                    s.push_back(queries[i][j]);
                }
                else{
                    s.push_back(queries[i][j]);
                }
            }
            res.push_back(s);
            for(int k = 0; k < res.size(); k++){
                cout << res[k] << " ";
            }
            cout << endl;
            int ct = 0;
            for(int i = 0; i < res.size(); i++){
                for(int j = 0; j < res[i].size() && ct < pattern.size(); j++){
                    if(pattern[ct] >= 'A' && pattern[ct] <= 'Z'){
                        if(res[i][j] == pattern[ct]){
                            mpp[pattern[ct]] -= 1;
                            ct++;
                        }
                    }
                    else{
                        if(res[i][j] == pattern[ct])    ct++;
                    }
                }
            }
            int flg = 0;
            for(auto&it: mpp){
                if(it.second >= 1)  flg = 1;
            }
            if(flg == 1 || ct < pattern.size()) ans.push_back(false);
            else    ans.push_back(true);    
        }
        return ans;
    }
};
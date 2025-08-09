class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string,string>>vect;
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            vect.emplace_back(temp,strs[i]);
        }
        sort(vect.begin(),vect.end());
        // for(auto&it:vect){
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<vector<string>>res;
        vector<string>ans;
        string prev = vect[0].first;
        ans.push_back(vect[0].second);

        for(int i = 1; i < n; i++){
            if(vect[i].first == prev)    ans.push_back(vect[i].second);
            else{
                res.push_back(ans);
                ans.clear();
                ans.push_back(vect[i].second);
            }
            prev = vect[i].first;
        }
        res.push_back(ans);
        return res;
    }
};
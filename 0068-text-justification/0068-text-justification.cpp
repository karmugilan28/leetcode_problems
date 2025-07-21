class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int ct = 0;
        int n = words.size();
        int maxi = maxWidth;
        vector<vector<int>>ans;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(maxi > words[i].size()){
                maxi -= (words[i].size()+1);
                sum += words[i].size();
                ct++;
            }
            else if(maxi == words[i].size()){
                maxi -= words[i].size();
                sum += words[i].size();
                ct++;
            }
            else{
                ans.push_back({ct,sum});
                ct = 0;
                sum = 0;
                maxi = maxWidth;
                i--;
            }
        }
        ans.push_back({ct,sum});
        maxi = maxWidth;
        int k = 0;
        // for(int i = 0; i < ans.size(); i++)  cout << ans[i][0] << " " << ans[i][1] << endl;
        vector<string>result;
        for(int i = 0; i < ans.size()-1; i++){
            int space1,flg = 0;
            if(ans[i][0]-1 != 0){
                space1 = (maxi - ans[i][1])/(ans[i][0]-1);
                flg = 1;
            }
            else    space1 = maxi-ans[i][1];
            int space2 = 0;
            
            if(flg == 1)    space2 = (maxi - ans[i][1]) % (ans[i][0]-1);
            string res ="";
            for(int j = k; j < k+ans[i][0]; j++){
                string s = words[j];
                int temp = space1;
                while(temp--){
                    s.push_back(' ');
                }
                if(space2){
                    s.push_back(' ');
                    space2--;
                }
                res += s;
            }
            // cout << maxi << endl;
            // if(res.size() > 16) res.erase()
            if(res.size() > maxi){
                int tem = space1,g = res.size()-1;
                while(tem--){
                    res.erase(g,1);
                    g--;
                }
            }
            result.push_back(res);
            k += ans[i][0];
            // cout << k << endl;
        }
        string res ="";
        for(int l = k; l < n; l++){
            res += words[l];
            if(l != n-1)    res.push_back(' ');
        }
        int sp = maxi - res.size();
        while(sp--){
            res.push_back(' ');
        }
        result.push_back(res);
        return result;
    }
};
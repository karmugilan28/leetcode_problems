class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<pair<int,int>>vect;
        int n = value.size();
        for(int i = 0; i < n ; i++){
            vect.emplace_back(value[i],limit[i]);
        }
        sort(vect.begin(),vect.end(),[&](const pair<int,int> a,const pair<int,int> b){
            if(a.second == b.second)  return a.first > b.first;
            return a.second  < b.second;
        });
        // for(int i = 0; i < n; i++){
        //     cout << vect[i].first << " " << vect[i].second << endl;
        // }
        int a = 1;
        long long tot = vect[0].first;
        int prev = vect[0].second;
        for(int i = 1; i < n; i++){
            if(vect[i].second == prev && a < vect[i].second){
                tot +=(long long)vect[i].first;
                a += 1;
            }
            else if(vect[i].second != prev){
                a = 1;
                tot += (long long)vect[i].first;
            }
            else if(a > vect[i].second){
                a = 0;
                int ind = upper_bound(vect.begin(),vect.begin()+n,vect[i].second,
                    [](int val,const pair<int,int>& vect){
                        return val < vect.second;
                    }
                ) - vect.begin();
                if(ind < n){
                    i = ind;
                }
            }
            prev = vect[i].second;
        }
        return tot;
    }
};
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int>mpp;
        for(int i = 0; i < bulbs.size(); i++){
            mpp[bulbs[i]]++;
        }
        vector<int>res;
        for(auto&it: mpp){
            if(it.second%2 != 0)
                res.push_back(it.first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
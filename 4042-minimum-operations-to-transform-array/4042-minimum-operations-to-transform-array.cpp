#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<ll,ll>>vect;
        int n = nums1.size();
        for(int i = 0; i < n; i++)    vect.emplace_back((ll)nums1[i],(ll)nums2[i]);
        sort(vect.begin(),vect.end(),[&](const pair<ll,ll>a,const pair<ll,ll>b){
            return a.second > b.second;
        });
        ll tot = 0;
        for(int i = 0; i < n; i++){
            tot += abs(vect[i].first-vect[i].second);
        }
        ll tar = (ll)nums2[n];
        int flg = 0;
        for(int i = 0; i < n; i++){
            if(tar >= vect[i].first && tar <= vect[i].second || tar >= vect[i].second && tar <= vect[i].first){
                flg = 1;
                break;
            }
        }
        if(flg == 1)    return tot+1;
        else{
            ll mini = LONG_LONG_MAX;
            for(int i = 0; i < n; i++)  mini = min(mini,abs(tar-(ll)nums1[i]));
            for(int i = 0; i < n; i++)  mini = min(mini,abs(tar-(ll)nums2[i]));
            return tot+mini+1;
        }
    }
};
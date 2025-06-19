class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        // int maxi = 0;
        // for(int i = 0; i < n; i++){
        //     int te = maxCost;
        //     int ct = 0;
        //     for(int j = i; j < n; j++){
        //         if(abs(int(s[j])-int(t[j]))<=te){
        //             ct++;
        //             te-=abs(int(s[j])-int(t[j]));
        //         }
        //         else    break;
        //     }
        //     maxi = max(maxi,ct);
        // }
        // return maxi;
        int l = 0,r = 0;
        int maxi = 0;
        int temp = maxCost;
        while(r < n){
            // if(abs(s[r]-t[r])<=temp)
            //     temp -= abs(s[r]-t[r]);
            while(abs(s[r]-t[r])>temp){
                temp += abs(s[l] - t[l]);
                l++;
            }
            if(abs(s[r] - t[r])<=temp){
                temp -= abs(s[r] - t[r]);
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};
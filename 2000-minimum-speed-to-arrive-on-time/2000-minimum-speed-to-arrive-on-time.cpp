class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int mini = *min_element(dist.begin(),dist.end());
        int maxi = *max_element(dist.begin(),dist.end());
        int mxi = INT_MAX;
        int low = 1, high = 1e7;
        while(low <= high){
            int mid = (low+high)/2;
            double ans = 0.0000;
            int ct = 0;        
            for(int j = 0; j < n; j++){
                double speed = (double)dist[j]/(double)mid;
                if(dist[j] % mid != 0 && j != n-1)    ans += floor(speed)+1;
                else if(dist[j]%mid != 0 && j == n-1) ans += speed;
                else    ans += speed;
                if(ans <= hour) ct++;
                else    break;
            }
            cout << low << " " << mid << " " << high<< endl;
            if(ct == n){
                mxi = min(mxi,mid);
                high = mid-1;
            }
            else    low = mid+1;
        }
        if(mxi == INT_MAX)  return -1;
        return mxi;
    }
};
class Solution {
public:
    int numberOfArrays(vector<int>& arr, int low, int high) {
        vector<long long>res;
        res.push_back(19);
        int n=arr.size();
        for(int i=0;i<n;i++){
            long long c=res[i]+arr[i];
            res.push_back(c);
        }
        long long maxi=*max_element(res.begin(),res.end());
        long long c=maxi-high;
        for(int i=0;i<=n;i++)
            res[i]-=c;

        int flag=0;
        for(int i=0;i<=n;i++){
            if(res[i]>=low && res[i]<=high)
                flag=0;
            else{
                flag=1;
                break;
            }
        }
        if(flag==1)
            return 0;
        long long mini=*min_element(res.begin(),res.end());
        long long maxii=*max_element(res.begin(),res.end());
        int tot=0;
        int d=(abs(low-mini));
        int e=abs(high-maxii);
        tot+=(d+e);
        return tot+1;
    }
};
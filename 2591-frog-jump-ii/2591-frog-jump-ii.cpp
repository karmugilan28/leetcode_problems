class Solution {
public:
    int maxJump(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        if(n%2==0){
            for(int i=0;i<n-2;i+=2){
                int sum=arr[i+2]-arr[i];
                maxi=max(maxi,sum);
            }
            maxi=max(maxi,arr[n-1]-arr[n-2]);
            for(int i=n-1;i>=3;i-=2){
                int sum=arr[i]-arr[i-2];
                maxi=max(maxi,sum);
            }
            maxi=max(maxi,arr[1]-arr[0]);
        }
        else{
            for(int i=0;i<n-2;i+=2){
                if(i%2==0){
                    int sum=arr[i+2]-arr[i];
                    maxi=max(maxi,sum);
                }
            }
            maxi=max(maxi,arr[n-1]-arr[n-2]);
            for(int i=n-2;i>=2;i-=2){
                int sum=arr[i]-arr[i-2];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};
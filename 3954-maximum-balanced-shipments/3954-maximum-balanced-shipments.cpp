class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int maxi = weight[0];
        int len = 0;
        int flg = 0;
        for(int i = 0 ; i < n-1; i++){
            maxi = max(maxi,weight[i]);
            if(maxi != weight[i]){
                len++;
                maxi = weight[i+1];
                flg = 0;
            }
            else{
                maxi = max(maxi,weight[i+1]);
                flg = 1;
            }
        }
        if(flg == 1){
            if(maxi != weight[n-1])
                len++;
        }
        return len;
    }
};
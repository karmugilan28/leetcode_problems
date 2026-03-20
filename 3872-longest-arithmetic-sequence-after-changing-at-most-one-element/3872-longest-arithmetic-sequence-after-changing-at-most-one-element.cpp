class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n),r(n);
        l[0] = 1, l[1] = 2;
        for(int i = 2; i < n; i++){
            int d1 = nums[i]-nums[i-1];
            int d2 = nums[i-1]-nums[i-2];
            if(d1 == d2)    l[i] = l[i-1]+1;
            else    l[i] = 2;
        }

        r[n-1] = 1, r[n-2] = 2;
        for(int i = n-3; i >= 0; i--){
            int d1 = nums[i+1]-nums[i];
            int d2 = nums[i+2]-nums[i+1];
            if(d1 == d2)    r[i] = r[i+1]+1;
            else    r[i] = 2;
        }
        int tot = 2;
        for(int i = 1; i < n-1; i++){
            if((nums[i+1]-nums[i-1])%2 == 0){
                int curr = (nums[i+1]-nums[i-1])/2;
                if(i >= 2 && i+2 < n){
                    int lft = nums[i-1]-nums[i-2], rit = nums[i+2]-nums[i+1];
                    int l_len = l[i-1], r_len = r[i+1];
                    if(i >= 2 && curr != lft) l_len = 1;
                    if(i+2 < n && curr != rit)    r_len = 1;
                    tot = max(tot,l_len+1+r_len);
                }
                else{
                    if(i >= 2){
                        int lft = nums[i-1]-nums[i-2];
                        int l_len = l[i-1],r_len = 1;
                        if(curr != lft)   l_len = 1;
                        tot = max(tot,l_len+1+r_len);
                    }
                    else{
                        int rit = nums[i+2]-nums[i+1];
                        int r_len = r[i+1], l_len = 1;
                        if(curr != rit)   r_len = 1;
                        tot = max(tot,l_len+1+r_len);
                    }
                }
            }
            tot = max(tot,l[i-1]+1);
            tot = max(tot,r[i+1]+1);
        }
        tot = max(tot,r[1]+1);
        tot = max(tot,l[n-2]+1);
        return tot;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int a = 0,b = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]%2==0)    a++;
            else    b++;
        }
        if(abs(a-b)>=2) return -1;
        else{
            int tot = 0;
            if(a>b){
                int ct = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i]%2==0){
                        tot += abs(i-ct);
                        ct+=2;
                    }
                }   
            }
            else if (a == b){
                int ct = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i]%2==0){
                        tot += abs(i-ct);
                        ct+=2;
                    }
                }
                int cnt = 0,tot1 = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i]%2!=0){
                        tot1 += abs(i-cnt);
                        cnt += 2;
                    }
                }
                return min(tot,tot1);
            }
            else{
                int ct = 0;
                for(int i = 0; i < n; i++){
                    if(nums[i]%2!=0){
                        tot += abs(i-ct);
                        ct+=2;
                    }
                }
            }
            return tot;
        }   
    }
};
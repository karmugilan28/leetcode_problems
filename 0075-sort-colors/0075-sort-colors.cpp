class Solution {
public:
    void sortColors(vector<int>& nums) {
    //    sort(nums.begin(),nums.end());
    //    return ; 
    // for(int i=0;i<nums.size();i++){
    //     for(int j=0;j<=i;j++){
    //         if(nums[i]<nums[j]){
    //             swap(nums[i],nums[j]);
    //         }
    //     }
    // }
    // return;

    //DUTCH national flag algorithm
        int n = nums.size();
        int l = 0, mid = 0, high = n - 1;
        while(mid <= high){
            if(nums[mid] == 2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[l],nums[mid]);
                l++;mid++;
            }
            
        }
        return ;
    }
};
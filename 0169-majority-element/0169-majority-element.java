class Solution {
    public int majorityElement(int[] nums) {
        // HashMap<Integer,Integer> mpp = new HashMap<Integer,Integer>();
        // for(int i = 0; i < nums.length ; i++){
        //     mpp.put(nums[i],mpp.getOrDefault(nums[i],0)+1);
        // }
        // for(Map.Entry<Integer,Integer> entry: mpp.entrySet()){
        //     if(entry.getValue() >= (nums.length+1)/2)
        //         return entry.getKey();
        // }
        int n = nums.length;
        int prev = 0,ct = 0;
        for(int i = 0; i < n; i++){
            if(ct == 0){
                prev = nums[i];
                ct++;
            }
            else if(prev == nums[i])    ct++;
            else if(prev != nums[i])    ct--;
        }
        return prev;
    }
}
class Solution {
public:
    bool partitionArray(vector<int>& arr, int k) {
        int n = arr.size();
        // map<int,int>mpp,mp1;
        // vector<int>nums;
        // for(int i = 0; i < n; i++)  mp1[arr[i]] += 1;
        // int flg = 1;
        // while(flg == 1){
        //     flg = 0;
        //     for(auto&it:mp1){
        //         if(it.second > 0)   {nums.push_back(it.first);it.second -= 1;flg = 1;}
        //         else    mp1.erase(it.first);
        //     }
        // }
        // for(int i = 0; i < n; i++)  cout << nums[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++){
        //     if(mpp.size() >= k) mpp.clear();
        //     if(mpp.size() < k)    mpp[nums[i]] += 1;
        //     if(mpp.size() >= k) mpp.clear();
        //     // cout << mpp.size() << endl;
        // }
        // if(mpp.size() == 0) return true;
        // else{

        // }
        // return false;
        if(n % k == 0){
            int a = n/k;
            unordered_map<int,int>mpp;
            for(int i = 0; i < n; i++)  mpp[arr[i]] += 1;
            for(int i = 0 ; i < n; i++){
                if(mpp[arr[i]] > a) return false;
            }
            return true;
        }
        return false;
    }
};
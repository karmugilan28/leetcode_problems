class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        int fd = 0;
        for(int i = 0; i < n;i++){
            if(nums[i] == 0)    fd = 0;
            else{
                fd = 1;
                break;
            }
        }
        if(fd == 0) return "0";
        vector<string>res;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            res.push_back(s);
        }
        sort(res.begin(),res.end(),greater<string>());
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int l = 0,flg = 0;
                int mini,maxi;
                if(res[i].size() <= res[j].size() && res[i] != res[j]){
                    mini = res[i].size();
                    maxi = res[j].size();
                    while(l < maxi*3){
                        if(res[i][l%mini] > res[j][l%maxi])  {flg = 0;break;}
                        else if(res[i][l%mini] == res[j][l%maxi])    flg = 2;
                        else{
                            flg = 1;
                            break;
                        }
                        l++;
                    }
                    if(flg == 0)    swap(res[i],res[j]);
                }
                else if(res[j].size() < res[i].size() && res[i] != res[j]){
                    mini = res[j].size();
                    maxi = res[i].size();
                    while(l < maxi*3){
                        if(res[i][l%maxi] > res[j][l%mini])  flg = 0;
                        else if(res[i][l%maxi] == res[j][l%mini])    flg = 2;
                        else{
                            flg = 1;
                            break;
                        }
                        l++;
                    }
                    if(flg == 0)    swap(res[i],res[j]);
                }       
            }
        }
        // for(int i = 1; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //             int flg = 0;
        //             for(int g = 0; g < res[i].size(); g++){
        //                 int fd =0;
        //                 for(int k = 0; k < res[j].size(); k++){
        //                     if(res[i][g] >= res[j][k])  fd = 0;
        //                     else{
        //                         fd =1;
        //                         break;
        //                     }
        //                 }
        //                 if(fd == 0)
        //                 // if(res[i].size() == 1){
        //                 //     int fd = 0;
        //                 //     for(int k = 0; k < res[j].size(); k++){
        //                 //         if(res[i][0] >= res[j][k])  fd = 0;
        //                 //         else{
        //                 //             fd =1;
        //                 //             break;
        //                 //         }
        //                 //     }
        //                 //     if(fd == 0)
        //                 //         swap(res[i],res[j]);
        //                 // }
        //                 // else{
        //                 //     int l = 0;
        //                 //     int flg = 0;
        //                 //     while(l < min(res[i].size(),res[j].size())){
        //                 //         if(res[i][l] >= res[j][l])  flg = 0;
        //                 //         else{
        //                 //             flg = 1;
        //                 //             break;
        //                 //         }
        //                 //         l++;
        //                 //     }
        //                 //     if(flg == 0)    swap(res[i],res[j]);
        //                 // }
        //                 // if(fd == 1){
        //                 //     flg = 0;
        //                 // }
        //     }
        // }
        string str ="";
        for(int i = 0; i < n; i++){
            str += res[i];
        }
        return str;
    }
};
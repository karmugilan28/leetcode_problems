class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bot) {
        // int n=tops.size();
        // vector<int>temp1(n),temp2(n);
        // temp1=tops;
        // temp2=bottoms;
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int a=temp1[i];
        //     int flag=0,cnt=0;
        //     for(int j=0;j<n;j++){
        //         if(temp1[j]!=a){
        //             if(temp2[j]==a){
        //                 cnt++;
        //                 flag=0;
        //             }
        //             else{
        //                 flag=1;
        //                 break;
        //             }
        //         }
        //         else
        //             flag=0;
        //     }
        //     if(flag==0)
        //         mini=min(mini,cnt);
        // }
        // for(int i=0;i<n;i++){
        //     int a=temp2[i];
        //     int found=0,cnt=0;
        //     for(int j=0;j<n;j++){
        //         if(temp2[j]!=a){
        //             if(temp1[j]==a){
        //                 cnt++;
        //                 found=0;
        //             }
        //             else{
        //                 found=1;
        //                 break;
        //             }
        //         }
        //         else
        //             found=0;
        //     }
        //     if(found==0)
        //         mini=min(mini,cnt);
        // }
        // if(mini==INT_MAX)
        //     return -1;
        // return mini;
        int n=tops.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[tops[i]]+=1;
        }
        int f;
        int maxi=0;
        for(auto &it:mpp){
            if(maxi<it.second){
                maxi=it.second;
                f=it.first;
            }
        }
        int cnt=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=f){
                if(bot[i]==f){
                    cnt++;
                    flag=0;
                }
                else{
                    flag=1;
                    break;
                }
            }
            else
                flag=0;
        }
        int mini=INT_MAX;
        if(flag==0)
            mini=min(mini,cnt);

        map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[bot[i]]+=1;

        int maxii=0;
        int g;
        for(auto &itt:mp){
            if(maxii<itt.second){
                maxii=itt.second;
                g=itt.first;
            }
        }
        int ct=0;
        flag=0;
        for(int i=0;i<n;i++){
            if(bot[i]!=g){
                if(tops[i]==g){
                    ct++;
                    flag=0;
                }
                else{
                    flag=1;
                    break;
                }
            }
            else
                flag=0;
        }
        if(flag==0)
            mini=min(mini,ct);
        if(mini==INT_MAX)
            return -1;
        return mini;
    }
};
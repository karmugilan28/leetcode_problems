class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++)    mpp[s[i]] += 1;
        int maxi = 0;
        for(auto&it:mpp)
            maxi=max(maxi,it.second);
        if(maxi>(n+1)/2)    return "";
        else{
            vector<char>res(n,'0');
            vector<pair<int,int>>p;
            for(auto&it:mpp)
                p.emplace_back(it.first,it.second);

            sort(p.begin(),p.end(),[&](const pair<char,int>a,const pair<char,int>b){
                return a.second > b.second;
            });
            int cnt = 0;
            for(auto&it:p){
                while(it.second>0){
                    if(cnt<n){
                        res[cnt] = it.first;
                        cnt+=2;
                        it.second-=1;
                    }
                    else    break;
                }
            }
            int ct = 1;
            for(auto&it:p){
                while(it.second>0){
                    if(ct<n){
                        res[ct] = it.first;
                        ct += 2;
                        it.second-=1;
                    }
                    else    break;
                }
            }
            string ans = "";
            for(int i =0; i<n ;i++){
                ans.push_back(res[i]);
            }
            return ans;
            // string res = "";
            // vector<pair<char,int>>p;
            // for(auto&it:mpp){
            //     p.emplace_back(it.first,it.second);
            // }
            // sort(p.begin(),p.end(),[&](const pair<char,int>a,const pair<char,int>b){
            //     return a.second > b.second;
            // });
            
            // int flag=0;
            // for(auto&it:p){
            //     if(it.second>0) flag=1;
            // }
            // while(flag==1){
            //     for(auto&it:p){
            //         if(it.second>0){
            //             res+=it.first;
            //             it.second-=1;
            //         }
            //     }
            //     flag=0;
            //     for(auto&it:p){
            //         if(it.second>0) flag=1;
            //     }
            // }
            // return res;
        }
    }
};
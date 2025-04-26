class Solution {
// public: 
//     int fn(int l,int r,string &s,int& t){
//         if(l>r)
//             return 0;
//         if(l==r)
//             return 1;
//         if(s[l]!=s[r]){
//             int f=fn(l+1,r,s,t);
//             int g=fn(l,r-1,s,t);
//             return max(f,g);
//         }
//         else{
//             int f=fn(l+1,r-1,s,t);
//             t=l;
//             return f;
//         }
//     }
public:
    string longestPalindrome(string s) {
        //brute force
        int maxi=0,re;
        for(int i=0;i<s.size();i++){
            string res="";
            for(int j=i;j<s.size();j++){
                res.push_back(s[j]);
                int l=0,r=res.size()-1;
                int flag=0;
                while(l<=r){
                    if(res[l]!=res[r]){
                        flag=1;
                        break;
                    }
                    l++;
                    r--;
                }
                if(flag==0){
                    int c=res.size();
                    if(maxi<c){
                        maxi=c;
                        re=i;
                    }
                }
            }
          
        }
        string res="";
        for(int i=re;i<re+maxi;i++)
            res.push_back(s[i]);
        return res;

        //optimal approach
        // int n=s.size();
        // int t=0;
        // int ans=fn(0,n-1,s,t);
        // string res="";
        // for(int i=t;i<t+ans;i++){
        //     res.push_back(s[i]);
        // }
        // return res;
    }
};
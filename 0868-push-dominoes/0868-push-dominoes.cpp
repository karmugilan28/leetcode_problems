class Solution {
public:
    string pushDominoes(string s) {
        // int l=0,r=0;
        // string t="";
        // while(r<s.size() && l<s.size()){
        //     while(s[l]!='R' && l<s.size()){
        //         t.push_back(s[l]);
        //         l++;
        //     }
        //     while((s[r]!='L' || l>r) && r<s.size())
        //         r++;
        //     if(l>=s.size() || r>=s.size())
        //         break;
        //     int temp=l,temp1=r;
        //     cout << temp << " " << temp1 << endl;
        //     int ct=0;
        //     t.push_back('R');
        //     while(temp+1<=temp1){
        //         if(s[temp]=='.')
        //             ct++;
        //         temp++;
        //     }
        //     int flag=0;
        //     if(ct%2!=0)
        //         flag=1;
        //     int n=ct/2,a=ct/2;
        //     while(n--)
        //         t.push_back('R');
        //     if(flag==1) t.push_back('.');
        //     while(a--)  t.push_back('L');
        //     t.push_back('L');
        //     cout << t << endl;
        //     r++;
        //     l++;
        // }
        // return t;
        int n=s.size();
        vector<int>nums(n,0);
        int f=0;
        //positive force and we are searching a right "R" from left to right and update it
        for(int i=0;i<n;i++){
            if(s[i]=='R')
                f=n;
            else if(s[i]=='L')
                f=0;
            else
                f=max(f-1,0);
            nums[i]+=f;
        }
        f=0;
        // we are finding the  negative force by searching for "L" from right to left if we met "R" we make it zero
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L')
                f=n;
            else if(s[i]=='R')
                f=0;
            else
                f=max(f-1,0);
            // cout << nums[i] << " " << f << " ";
            nums[i]-=f;
            // cout << nums[i] << endl;
        }
        // cout << endl;
        string res="";
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                res.push_back('R');
            else if(nums[i]==0)
                res.push_back('.');
            else
                res.push_back('L');
        }
        return res;
    }
};
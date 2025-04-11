class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ct=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==0){
                int a=0;
                for(int i=0;i<s.size()/2;i++){
                    int temp=s[i]-'0';
                    a+=temp;
                }
                int b=0;
                for(int i=s.size()/2;i<s.size();i++){
                    int temp=s[i]-'0';
                    b+=temp;
                }
                if(a==b)
                    ct++;
            }
        }
        return ct;
    }
};
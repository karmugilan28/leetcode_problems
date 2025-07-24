class Solution {
public:
    string getEncryptedString(string s, int k) {
        string str1;
        int n = s.size();
        int f = k % n;
        for(int i=0;i<s.size();i++){
            if((i+f)>=s.size()){
               int num1=i+f;
               int c=num1-s.size();
               str1=str1+s[c]; 
            }
            else{
                str1=str1+s[i+f];
            }
        }
        return str1;
    }
};
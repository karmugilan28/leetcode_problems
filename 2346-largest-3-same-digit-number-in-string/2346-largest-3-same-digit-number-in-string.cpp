class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string maxi = "";
        for(int i = 0; i < n-2; i++){
            string str ="";
            str.push_back(num[i]);
            str.push_back(num[i+1]);
            str.push_back(num[i+2]);
            map<char,int>mpp;
            mpp[num[i]] += 1, mpp[num[i+1]] += 1 , mpp[num[i+2]] += 1;
            if(mpp.size() == 1) maxi = max(maxi,str);
        }
        return maxi;
    }
};
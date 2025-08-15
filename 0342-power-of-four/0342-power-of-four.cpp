class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true; 
        else if(n%4!=0)
            return false;
        return isPowerOfFour(n/4);
        // if(n==4 || n==16 || n==64 || n==256 || n==1 || n==1024 )
        //     return true;
        // if(n>=1024){
        //     if(n%4==0 && n%16==0 && n%64==0 && n%256==0 && n%1024==0)
        //         return true;
        //     else    return false;
        // }
        // else
        //     return false;
        // else if(n>=64){
        //     if(n%4==0 && n%16==0 && n%64==0)
        //         return true;
        //     else    return false;
        // }
        // else if(n>=16){
        //     if(n%4==0 && n%16==0)
        //         return true;
        //     else    return false;
        // }
        // else if(n>=4)
        //     return false;
        // else{
        //     return false;
        // }
    }
};
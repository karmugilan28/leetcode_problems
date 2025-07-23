class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int i=0;
        int count=0,add=0;
        if(x>y){
            while(i<s.size()){
                if(s[i]=='a' && s[i+1]=='b'){
                    count=count+x;
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    if(i<=0)
                        i=0;
                    else{
                        i--; 
                    }
                    
                }
                else{
                    i++;
                }
            }
            i=0;
            while(i<s.size()){
                if(s[i]=='b' && s[i+1]=='a'){
                    add=add+y;
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    if(i<=0)
                        i=0;
                    else{
                        i--; 
                    }
                }
                else{
                    i++;
                }
            }
        }
        else if(y>=x){
            while(i<s.size()){
                if(s[i]=='b' && s[i+1]=='a'){
                    count=count+y;
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    if(i<=0)
                        i=0;
                    else{
                        i--; 
                    }
                    
                    
                }
                else{
                    i++;
                }
                
            }
            i=0;
            while(i<s.size()){
                if(s[i]=='a' && s[i+1]=='b'){
                    add=add+x;
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    if(i<=0)
                        i=0;
                    else{
                        i--; 
                    }  
                }
                else {
                    i++;
                }
            }
        }
        
        return count+add;
    }
};
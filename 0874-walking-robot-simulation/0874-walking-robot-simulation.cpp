class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        int n = com.size(), m = obs.size();
        int r = 0, c = 0;
        char a = 'N';
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(a == 'N'){
                if(com[i] >= 1){
                    int tc = c + com[i],tr = r;
                    for(int j = 0; j < m; j++){
                        if((obs[j][0] == r && (obs[j][1] > c && obs[j][1] <= tc))){
                            tc = min(tc,obs[j][1]-1);
                        }
                    }
                    c = tc;
                }
                else if(com[i] == -1)    a = 'W';
                else    a = 'E';
                
            }
            else if(a == 'W'){
                if(com[i] >= 1){
                    int tr = r + com[i], tc = c;
                    for(int j = 0; j < m; j++){
                        if(obs[j][1] == tc && (obs[j][0] > r && obs[j][0] <= tr)){
                            tr = min(tr,obs[j][0]-1);
                        }
                    }
                    r = tr;
                }
                else if(com[i] == -1)    a = 'S';
                else    a = 'N';
            }
            else if(a == 'E'){
                if(com[i] >= 1){
                    int tr = r - com[i], tc = c;
                    for(int j = 0; j < m; j++){
                        if(obs[j][1] == tc && (obs[j][0] < r && obs[j][0] >= tr))
                            tr = max(tr,obs[j][0]+1);
                    }
                    r = tr;
                }
                else if(com[i] == -1)   a = 'N';
                else    a = 'S';
            }
            else{
                if(com[i] >= 1){
                    int tr = r, tc = c-com[i];
                    for(int j = 0; j < m; j++){
                        if(obs[j][0] == tr && obs[j][1] < c && obs[j][1] >= tc)
                            tc = max(tc,obs[j][1]+1);
                    }
                    c = tc;
                }
                else if(com[i] == -1)   a = 'E';
                else    a = 'W';
            }
            int d = (abs(r)*abs(r)) + (abs(c)*abs(c));
            maxi = max(maxi,d);
            cout << r << " " << c << " " << d << endl;
        }
        return maxi;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            map<char,int>mpp;
            for(int j=0;j<9;j++){
                if(board[j][i]>='1' && board[j][i]<='9'){
                    mpp[board[j][i]] +=1;
                    if(mpp[board[j][i]]>1){
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<9;i++){
            map<char,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]>='1' && board[i][j]<='9'){
                    mp[board[i][j]] +=1;
                    if(mp[board[i][j]]>1){
                        return false;
                    }
                }
            }
        }
        cout << "correct";
    for(int k=0;k<9;k=k+3){
        map<char,int>a;
        map<char,int>b;
        map<char,int>c;
        for(int i=k;i<k+3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]>='1' && board[i][j]<='9'){
                    a[board[i][j]]+=1;
                    if(a[board[i][j]]>1){
                        return false;
                    }
                } 
            }
            cout << "correct"<<"\n";
            for(int j=3;j<6;j++){
                if(board[i][j]>='1' && board[i][j]<='9'){
                    b[board[i][j]] +=1;
                    if(b[board[i][j]]>1){
                        return false;
                    }
                }
            }
            cout << "correct"<<"\n";

            for(int j=6;j<9;j++){
                if(board[i][j]>='1' && board[i][j]<='9'){
                    c[board[i][j]] +=1;
                    if(c[board[i][j]]>1){
                        return false;
                    }
                }
            }   
        }
    }
    return true;
    }
   
};
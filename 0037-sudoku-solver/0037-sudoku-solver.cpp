class Solution {
public:
    bool ispossible(int m,int n,vector<vector<char>>& board,char k){
        for(int i=0;i<board.size();i++){
            if(board[m][i]==k)
                return false;
            if(board[i][n]==k)
                return false;
        }
        int a=m/3,b=n/3;
        for(int i=a*3;i<(a*3)+3;i++){
            for(int j=b*3;j<(b*3)+3;j++){
                if(board[i][j]==k){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(ispossible(i,j,board,k)){
                            board[i][j]=k;
                            if(solve(board)==true)
                                return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return ;
    }
};
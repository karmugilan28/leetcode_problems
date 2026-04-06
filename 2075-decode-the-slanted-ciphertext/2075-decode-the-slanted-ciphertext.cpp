class Solution {
public:
    string decodeCiphertext(string t, int r) {
        int nt = t.size();
        int c = nt/r;
        vector<vector<char>>grid(r,vector<char>(c,' '));
        int a = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                grid[i][j] = t[a++];
            }
        }
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++)
        //         cout << grid[i][j] << " ";
        //     cout << endl;
        // }
        string str = "";
        for(int j = 0; j < c; j++){
            int ri = 0, cj = j;
            while(ri < r && cj < c){
                str.push_back(grid[ri][cj]);
                ri++; cj++;
            }
        }
        for(int i = str.size()-1; i >= 0; i--){
            if(str[i] != ' ')   break;
            str.pop_back();
        }
        return str;
    }
};
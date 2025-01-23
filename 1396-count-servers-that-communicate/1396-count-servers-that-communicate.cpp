class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //brute force approach
        int tot=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int flag=0;
                if(grid[i][j]==1){
                    for(int k=j+1;k<grid[i].size();k++){
                        if(grid[i][k]==1){
                           flag=1;
                           break;
                        }
                    }
                    if(flag==0){
                        for(int l=i+1;l<grid.size();l++){
                            if(grid[l][j]==1){
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==0){
                        for(int l=i-1;l>=0;l--){
                            if(grid[l][j]==1){
                                flag=1;
                                break;
                            }       
                        }
                    }
                    if(flag==0){
                        for(int k=j-1;k>=0;k--){
                            if(grid[i][k]==1){
                                flag=1;
                                break;
                            }
                        }
                    }
                }
                if(flag==1)
                    tot+=1;
            }
        }
        return tot;
    }
};
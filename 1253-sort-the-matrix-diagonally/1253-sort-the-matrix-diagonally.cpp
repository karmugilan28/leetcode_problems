class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int j=m-1;j>=0;j--){
            vector<int>arr;
            int r=j;
            for(int i=0;i<n;i++){
                if(i<n && r<m){
                    arr.push_back(mat[i][r]);
                    r++;
                }
                else
                    break;
            }
            sort(arr.begin(),arr.end());
            int l=j;
            for(int i=0;i<n;i++){
                if(i<n && l<m){
                    mat[i][l]=arr[i];
                    l++;
                }
                else
                    break;
            }
        }

        for(int i=n-1;i>0;i--){
            vector<int>arr;
            int r=i;
            for(int j=0;j<m;j++){
                if(j<m && r<n){
                    arr.push_back(mat[r][j]);
                    r++;
                }
                else
                    break;
            }
            sort(arr.begin(),arr.end());
            int l=i;
            for(int j=0;j<m;j++){
                if(l<n && j<m){
                    mat[l][j]=arr[j];
                    l++;
                }
                else
                    break;
            }
        }
        
        return mat;
    }
};
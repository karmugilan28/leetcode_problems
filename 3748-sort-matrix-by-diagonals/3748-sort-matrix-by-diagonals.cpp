class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=n-1;i>=0;i--){
            vector<int>nums;
            for(int j=0,k=i;k<n && j<n; k++,j++){
                nums.push_back(grid[k][j]);
            }
            sort(nums.begin(),nums.end(),greater<int>());
            int a=0;
            for(int j=0,k=i;k<n && j<n;k++,j++){
                grid[k][j]=nums[a];
                a++;
            }
        }
        for(int j=1;j<n;j++){
            vector<int>arr;
            for(int i=0,k=j; k<n && i<n-1;i++, k++){
                arr.push_back(grid[i][k]);
            }
            sort(arr.begin(),arr.end());
            int a=0;
            for(int i=0,k=j;k<n && i<n-1 ;i++,k++){
                grid[i][k]=arr[a];
                a++;
            }
        }
        return grid;
    }
};
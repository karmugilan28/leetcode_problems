class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int sum = 0;
        for(int i = 0; i < n-1; i++){
            int c = abs(points[i][1]-points[i+1][1]);
            int temp1 = points[i][0]+c;
            int temp2 = points[i][0]-c;
            int s1 = c + abs(temp1-points[i+1][0]);
            int s2 = c + abs(temp2-points[i+1][0]);
            int d = abs(points[i][0]-points[i+1][0]);
            int temp3 = points[i][1]+d;
            int temp4 = points[i][1] - d;
            int s3 = d + abs(temp3-points[i+1][1]);
            int s4 = d + abs(temp4-points[i+1][1]);
            sum += min({s1,s2,s3,s4});
        }
        return sum;
    }
};
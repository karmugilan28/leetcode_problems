class Solution {
public: 
    int fn(int i,int next,vector<int>&days,vector<int>&costs,vector<vector<int>>&dp){
        if(i>=days.size())
            return 0;
        if(dp[i][next]!=-1)
            return dp[i][next];
        int one=INT_MAX;
        if(next<days[i])
            one=costs[0]+fn(i+1,days[i],days,costs,dp);
        else
            one=0+fn(i+1,next,days,costs,dp);
        
        int seven=INT_MAX;
        if(next<days[i])
            seven=costs[1]+fn(i+1,days[i]+6,days,costs,dp);
        else
            seven=0+fn(i+1,next,days,costs,dp);

        int thirty=INT_MAX;
        if(next<days[i])
            thirty=costs[2]+fn(i+1,days[i]+29,days,costs,dp);
        else
            thirty=0+fn(i+1,next,days,costs,dp);
        return dp[i][next]=min(one,min(seven,thirty));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<vector<int>>dp(n,vector<int>(10000,-1));
        return fn(0,0,days,costs,dp);
    }
};
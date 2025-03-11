class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n=skill.size();
        int flag=0;
        sort(skill.begin(),skill.end());
        int l=0,r=n-1;
        long long tot=0;
        int temp=skill[0]+skill[n-1];
        while(l<r){
            if(temp==skill[l]+skill[r]){
                flag=0;
                tot+=(skill[l]*skill[r]);
            }
            else{
                flag=1;
                break;
            }
            l++;
            r--;
        }
        if(flag==0)
            return tot;
        return -1;
    }
};
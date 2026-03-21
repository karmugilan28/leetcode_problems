class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(),t.end());
        if(s == t)  return 0;
        if(n == 2)  return -1;

        int ct = 0;
        string tem = s;
        char curr = tem[n-1];
        tem.pop_back();
        sort(tem.begin(),tem.end());
        tem.push_back(curr);
        if(tem == t)   ct = 1;
        else{
            ct++;
            char fr = tem[0];
            tem.erase(0,1);
            sort(tem.begin(),tem.end());
            string temp = "";
            temp.push_back(fr);
            temp += tem;
            if(temp == t)   ct++;
            else    ct = 3;
        }
        int cnt = 0;
        string tempo = s;
        char f = tempo[0];
        tempo.erase(0,1);
        sort(tempo.begin(),tempo.end());
        string temp = "";
        temp.push_back(f);
        temp += tempo;
        if(temp == t)   cnt = 1;
        else{
            cnt++;
            curr = temp[n-1];
            temp.pop_back();
            sort(temp.begin(),temp.end());
            temp.push_back(curr);
            if(temp == t)   cnt++;
            else    cnt = 3;
        }
        cout << ct << " " << cnt << endl;
        return min(ct,cnt);
        
    }
};
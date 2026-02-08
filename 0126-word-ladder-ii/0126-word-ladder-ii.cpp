class Solution {
public:
    void fn(string curr,string st,unordered_set<string>&words,vector<string>&arr,vector<vector<string>>&res,map<string,int>&mpp){
        for(int i = 0; i < curr.size(); i++){
            for(char a = 'a'; a <= 'z'; a++){
                string temp = curr;
                temp[i] = a;
                vector<string>tempo = arr;
                if(temp == st && mpp[temp] == 1){
                    tempo.push_back(temp);
                    res.push_back(tempo);
                    return ;
                }
                else if(words.contains(temp) && mpp[temp] == mpp[curr]-1){
                    tempo.push_back(temp);
                    fn(temp,st,words,tempo,res,mpp);
                }
            }
        }
        return ;
    }
public:
    vector<vector<string>> findLadders(string st, string end, vector<string>& w) {
        // queue<pair<vector<string>,int>>q;
        // vector<string>arr = {st};
        // q.push({arr,1});
        unordered_set<string>word,words;
        vector<vector<string>>res;
        for(int i = 0; i < w.size(); i++)    word.insert(w[i]);
        words = word;
        // int k = 1,mini = INT_MAX;
        // while(!q.empty()){
        //     vector<string>temp = q.front().first;
        //     int level = q.front().second;
        //     for(int i = 0; i < temp[0].size(); i++){
        //         string curr = temp[temp.size()-1];
        //         for(char a = 'a'; a <= 'z'; a++){
        //             vector<string>arr = temp;
        //             curr[i] = a;
        //             if(curr == end && word.contains(curr) && curr != temp[temp.size()-1]){
        //                 arr.push_back(end);
        //                 if(mini > (int)arr.size()){
        //                     mini = (int)arr.size();
        //                     res.push_back(arr);
        //                 }
        //                 else if(mini == (int)arr.size()){
        //                     res.push_back(arr);
        //                 }
        //                 break;
        //             }
        //             if(word.contains(curr) && curr != temp[temp.size()-1]){
        //                 arr.push_back(curr);
        //                 q.push({arr,level+1});
        //             }
        //         }
        //     }
        //     if(level == k){
        //         word.erase(temp[temp.size()-1]);
        //         k++;
        //     }
        //     q.pop();
        // }
        // return res;

        queue<pair<string,int>>q;
        q.push({st,1});
        map<string,int>mpp;
        mpp[st]++;
        int mini = INT_MAX;
        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            for(int i = 0; i < curr.size(); i++){
                for(char a ='a'; a <='z'; a++){
                    string temp = curr;
                    temp[i] = a;
                    if(temp == end && word.contains(temp) && temp != curr){
                        mpp[temp] = level+1;
                        mini = min(mini,level+1);
                        word.erase(temp);
                    }
                    else if(word.contains(temp) && temp != curr){
                        q.push({temp,level+1});
                        if(mpp[temp] > 0)   mpp[temp] = min(mpp[temp],level+1);
                        else    mpp[temp] = level+1;
                        word.erase(temp);
                    }
                }
            }
            q.pop();
        }
        cout << mini << endl;
        for(auto it:mpp)    cout << it.first << " " << it.second << endl;
        if(mpp[end] == 0)   return res;
        vector<string>arr = {end};
        fn(end,st,words,arr,res,mpp);
        for(int i = 0; i < res.size(); i++){
            reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};
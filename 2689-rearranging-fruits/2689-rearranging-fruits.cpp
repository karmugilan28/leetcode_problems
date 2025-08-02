class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        // map<int,int>mpp;
        // for(int i = 0; i < n; i++)  {mpp[b1[i]] += 1; mpp[b2[i]] +=1;}
        // int flg = 0;
        // for(auto&it: mpp){
        //     if(it.second % 2 != 0)  flg = 1;
        // }
        // if(flg == 1)    return -1;
        // sort(b1.begin(),b1.end());
        // sort(b2.begin(),b2.end());
        // for(int i = 0; i < n; i++)  cout << b1[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < n; i++)  cout << b2[i] << ' ';
        // cout << endl;
        // unordered_map<int,int>mp1,mp2;
        // for(int i = 0; i < n; i++)  mp1[b1[i]] += 1;
        // for(int i = 0; i < n; i++)  mp2[b2[i]] += 1;
        // // for(auto&it:mp1)    cout << it.first << " " << it.second << endl;
        // // for(auto&it:mp2)    cout << it.first << " " << it.second << endl;
        // long long sum = 0;
        // for(auto &it:mp1){
        //     int a = it.first, b = it.second, c = mp2[a];
        //     if(b > c){
        //         for(auto &itt:mp2){
        //             int d = itt.first , e = itt.second, f = mp1[d];
        //             if(e > f){
        //                 int swap1 = abs(c-b)/2;
        //                 int swap2 = abs(f-e)/2;
        //                 if(swap1 > swap2){
        //                     mp1[a] -= swap2;
        //                     mp2[a] += swap2;
        //                     mp1[d] += swap2;
        //                     mp2[d] -= swap2; 
        //                     sum += (long long)swap2 * (long long)min(a,d);
        //                 }
        //                 else if(swap1 <= swap2){
        //                     mp1[a] -= swap1;
        //                     mp2[a] += swap1;
        //                     mp1[d] += swap1;
        //                     mp2[d] -= swap1;
        //                     sum += (long long)swap1 * (long long)min(a,d);
        //                 }
        //             }
        //         }
        //     }
        // } 
        // return sum;
        int mini = INT_MAX;//we find minimum because if the remaing fruits have big cost and a particular fruit has so min cost like
        // 8 or 3 then we can swapp multiple times by using this multiple swapping of minimum fruit which gives the most minimal naswer in some test case
        unordered_map<int,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[b1[i]]++;
            mini = min(mini,b1[i]);
        }
        for(int i = 0; i < n; i++){
            mpp[b2[i]]--;
            mini = min(mini,b2[i]);
        }
        vector<int>remain;
        for(auto&it: mpp){
            if(it.second % 2 != 0)  return -1;
            for(int i = 0; i < abs(it.second)/2; i++)
                remain.push_back(it.first);//here we push the element which are in excess eg 8 is present 4 times ,then we will store 8 two times in this excess list since we swap atmost two from one basket to other basket
        }
        sort(remain.begin(),remain.end());//sort the remain vector since we want the minimum swap value
        // cout << mini << endl;
        // for(int i = 0; i < remain.size(); i++)  cout << remain[i] << ' ';
        // cout << endl;
        long long cost = 0;
        for(int i = 0; i < remain.size()/2; i++){//here we are iterationg only till remain.size()/2 because we are swapping two elements which we can swap the first element with any other element in the remain list
        //so to swap elemnts we take min(a,b) so we consider only hals]f elemnts which are minimum in list
            cost += (min((long long)remain[i],2LL*mini));
        }
        return cost;
    }
};
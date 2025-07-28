class Solution {
public:
    long long countVowels(string word) {
        // long long sum=0;
        // int n = word.size();
        // for(int i = 0; i < n; i++){
        //     int cnt = 0;
        //     for(int j = i; j < n; j++){
        //         if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
        //             cnt++;
        //         if(cnt > 0) sum += cnt;
        //     }
        // }
        // return sum;
        int n = word.size();
        vector<long long>prev(n);
        long long cnt = 0;
        for(int j = 0; j < n; j++){
            if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
                cnt++;
            prev[j] = cnt;
        }

        long long sum = 0;
        for(int i = 0; i < n; i++)  sum += prev[i];
        
        long long maxi = sum;
        for(int j = 0; j < n; j++){
            if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'){
                sum -= (n-j);
            }
            maxi += sum;
        }
        return maxi;
    }
};
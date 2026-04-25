class Solution {
public:
    int beautySum(string s) {
        int total = 0;
 int n = s.length();
        map<char, int> mpp1;

        for (int i = 0; i < n ; i++) {
            for (int j = i; j <n ; j++)// fix i and move j , taking new character will makes new substring or increase frequency of current character 
             {
                mpp1[s[j]]++;

                int maxi = INT_MIN;

                int mini = INT_MAX;

                for (auto it : mpp1)//find max and min frequency.
                 {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                total += maxi - mini;
            } // inner loop ends

            mpp1.clear();
        }

        return total;
    }
};
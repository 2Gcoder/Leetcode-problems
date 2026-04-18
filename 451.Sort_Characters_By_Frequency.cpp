class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        vector<pair<int, char>> vec;

        for (char ch : s) {
            mpp[ch]++;
        }
        for (auto it : mpp) {
            vec.push_back( {it.second,it.first} ); // it.second--> frquency , it.first --> character
        }

sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });// this is for customizing sorting pairs in vector in decreasing order of frequency 

      
        s.clear();

        for(auto it : vec)
        {
            for(int i=0;i<it.first;i++)
            {
                s  += it.second;
            }
        }

        return s;
    }
};
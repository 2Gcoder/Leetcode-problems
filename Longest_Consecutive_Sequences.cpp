class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(
            nums.begin(),
            nums.end()); // converting vector into set .so that we can delete
                         // the element after certain condition mentioned below

        int lonng = 0;

        for (int num : st) {
            int count = 1;
            if (st.find(num - 1) ==
                st.end()) // finding smallest value in set . after getting the
                          // smallest value while loop run
            {
                while (st.find(num + 1) != st.end())
                                 // increasing num+1 , and checking that num+1
                                 // exist or not .if it is exist then we get
                                 // consecutive . so we delete num from set .

                {
                    count++;
                    num++;
                    st.erase(num);
                }

                lonng = max(count, lonng);
            }
        }
        return lonng;
    }
};
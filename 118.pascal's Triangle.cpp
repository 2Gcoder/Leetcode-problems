class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; // ans is vector who stores vector
        for (int i = 1; i <= numRows; i++) // loop to call function who make entire row
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    } // generate function end here
    vector<int> generateRow(int row) // it is another function we call so it has  define outside of  generate function
    {
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for (int col = 1; col < row;col++) // This loop is for making the row named as ansrow .'
                    // ansrow' is vector which going to store in 'ans' vector.
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
};
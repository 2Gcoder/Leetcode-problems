class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, n, m, row = matrix.size();

        for (i = 0; i < row;
             i++) // Swaping opposite element of indexs([i][j] to [j][i]) across
                  // diagonal . Diagonal is from uppermost right to lowermost
                  // left for this given loop . or it  can be from uppermost
                  // left to lowermost right.
        {

            for (j = 0; j < row - i; j++) {
                n = row - j - 1;
                m = row - i - 1;
                swap(matrix[i][j], matrix[n][m]);
            }
        }

        for (i = 0; i < row / 2;
             i++) // Swaping the first row to last . second to second last row
                  // and so on . because diagonal is  from uppermost right to
                  // lowermost left .

        //  BUT if diagonal is from uppermost left to lowermost right then swap
        //  columns , first to last and second to secondlast so on.

        // using two pointer in row 'i' and 'n'
        {
            int n = row - i - 1;
            for (j = 0; j < row; j++)
                swap(matrix[i][j], matrix[n][j]);
        }
        return;

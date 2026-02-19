class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, rows = matrix.size(), cols = matrix[0].size(), col0 = 1;
        for (i = 0; i < rows;
             i++) // if we get zero then make uppermost row and leftmost column
                  // makes zero . we this we don't need extra space
        {
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if (j != 0) // if we get zero in leftmost column then store
                                // that zero in 'col0' variable .
                        matrix[0][j] = 0;

                    else
                        col0 = 0;
                }
            }
        }

        for (i = 1; i < rows; i++)

        {
            for (j = 1; j < cols; j++)

            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) // index [0][0] has zero then make all column
                               // zero if first row contains zero
        {
            for (j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        if (col0 == 0) // if we get zero in first column then  make first zero .
        {
            for (i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }

        //  This is a edge case where first row and column has have same index
        //  to store zero . which make first row and column  zero if only the
        //  first row has zero  and it uncessarly makes first column zero and
        //  vice-versa. so , we store zero of first column in variable 'col0'
        //  and first row's zero in index[0][0].
        return;
    }
    // time complexity O(M*N)
    // space complexity O(1)
};
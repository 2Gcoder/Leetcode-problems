class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty())
            return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        //  At each layer of matrix:

        // Move right along first row(left --> right) after loop end (top++) to avoid reprinting 
        

        // Move down along last column(top --> bottom) after loop end (right--) to avoid reprinting

        // Move left along last row (if still valid) (right --> left) after loop end (bottom--) to avoid reprinting  

        // Move up along first row (if still valid)(bottom --> top) after loop end (left) to avoid reprinting 

       // boundaries are updated after each loop
        while (top <= bottom && left <= right) {
            // Move right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Move down
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Move left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Move up
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

bool search(vector<vector<int>>& matrix, int target,
            int col) // applying binary search on each row
{
    int st = 0, end = matrix.size() - 1;
    if (matrix[end][col] <
        target) // If last value of row is  less than target then  applying
                // binary search in that is completely waste.so return false .
        return false;

    while (st <= end) // if while is runs in any row then target must be in that
                      // row (because target is less than last element and next
                      // other element after that last value is always
                      // greater)and if not then target in not in whole matrix .
    {
        int mid = (st + end) / 2;
        if (matrix[mid][col] == target)
            return true;

        else {
            if (matrix[mid][col] <= target)
                st = mid + 1;

            else
                end = mid - 1;
        }
    }
    return false;
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i;

        for (i = 0; i < matrix[0].size(); i++) {
            if (search(matrix, target, i))
                return true;
        }
        return false;
    }
};
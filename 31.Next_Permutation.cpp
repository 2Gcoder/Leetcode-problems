class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j, n = nums.size() - 1, mini = INT_MAX, index = 0;
        int i = n, in = -1;
        // examples :{2,4,1,5,7,8} next  permutation {}

        for (i = n; i >= 1; i--) {

            if (nums[i - 1] < nums[i]) {

                // moving from right to left in which previous number is larger
                // . it store index where this condition false(previous number
                // is smaller)
                in = i - 1;
                break;
            }
        }
        if (in ==
            -1) { // if given in it's highest permutation already then swap
                  // array to get smallest . ex. {5,1,1} gives {1,1,5}
            for (int i = 0; i <= n / 2; i++)
                swap(nums[i], nums[n - i]);

            return;
        }

        for (int k = in; k < nums.size();
             k++) { // searching to the right from index(in) for the number
                    // which is slightly greater than that index(in)'s value .
            if (nums[in] < nums[k]) {
                if (mini != min(nums[k], mini)) {
                    index = k;
                    mini = nums[k];
                }
            }
        }

        swap(nums[in], nums[index]); // swap this two numbers.

        sort(nums.begin() + in + 1,
             nums.end()); // from index(in)sort all element of right hand side.

        return;
    }
};
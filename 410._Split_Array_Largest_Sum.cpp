class Solution {
public:
    bool allocation(int barrier, vector<int> nums,int n)
             // function to check for every mid , mid is maximum
                           // pages should allocate to each student
    {
        int as = 1, pages = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > barrier)
                return false;

            if (nums[i] + pages > barrier) {
                as++;
                pages = nums[i];
            }

            else {
                pages += nums[i];
            }
        }

        if (as > n) // as is student required for page distribution for
                    // particular mid , n is no. of given student
            return false;

        else
            return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int result = 0, low = 0, high = 0, mid;

        for (int i = 0; i < nums.size(); i++) // taking search space
        {
            low = max(low, nums[i]);
            high += nums[i];
        }

        while (low <= high) {
            mid = (low + high) / 2;

            if (allocation(mid, nums,
                           k)) // if true , then we go for more minimum value
            {
                result = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return result;
    }
};
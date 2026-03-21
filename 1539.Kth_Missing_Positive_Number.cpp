class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        // int n = arr.size();
        // int i;

        // for(i=0;i<n;i++)  FIRST APPROACH
        // {
        //     if(arr[i] <= k) k++;

        //     else break;
        // }

        // return k;

        // SECOND APPROACH
        int n = arr.size();
        int i = 0, low = 0, high = n - 1, mid;

        while (low <= high)

        {
            mid = (low + high) / 2;
            int mis;
            mis = arr[mid] - mid - 1;

            if (mis < k)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return (low + k);
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1;
        int remain = j + 1 - k;
        if (remain < 0)
            remain = -remain;

        while (nums.size() < k) {
            if (nums.size() == 1 || nums.size() < k)
                k = k - nums.size();
        }
       
        while (i < j) {// reverse the array 
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

       

        for (i = 0; i < k / 2; i++) { // reverse array from 0 to k from starting 
            swap(nums[i], nums[k - i - 1]);
        }

        int count = 0;
        int z = nums.size() - 1;
        for (i = k; i < z; i++)//reverse from k+1 to last of array 

        { 
            int f = (nums.size() - k) / 2;
            if (f != count || remain == 1) {
               
                swap(nums[i], nums[z]);
                count++;
                z--;
            }

            else {
                break;
            }
        }
    }
};
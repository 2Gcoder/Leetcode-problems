class Solution {
public:
    int findMin(vector<int>& nums) {
        int st =0 , end = nums.size() -1 ,ans =0,result  = INT_MAX;

        while(st <= end)
        {
         int  mid =st + (end - st)/2;

            if(nums[st] <= nums[mid])// if we get sorted left side . store nums[st] in ans which smallest in this left side array . then go to unsorted side, were the repeating element are present or first element of original sorted array.
          {  ans = nums[st];
          st = mid+1;
          }

          else{  // If right side is sorted , then  mid is smallest , store it and move to left side , to get first element of original sorted array.
           ans = nums[mid];
           end = mid - 1;
          }

            if(ans < result )// to compare the previous ans to get smallest or  first element of original sorted array.
            result =ans;
        }

        return result;
    }
};
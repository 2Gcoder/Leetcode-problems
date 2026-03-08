class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ind1 = -1 ,ind2 = -1,i,j , st=0 , end = nums.size()-1;

        while(st <= end) // finding index of first ocurrence of target moving on right side
        {
            int mid = st + (end-st)/2;

            if(nums[mid] == target)
          {
            ind1=mid;
            end = mid - 1;
          }

          else if(nums[mid]  > target)
             end = mid - 1; 

             else st = mid +1;        

        }

        while(st<=end) // finding index of last ocurrence of target moving on left side
        {  int mid = st + (end-st)/2;

            if(nums[mid] == target)
          {
            ind2=mid;
            st = mid + 1;
          }

          else if(nums[mid]  > target)
             end = mid - 1; 

             else st = mid +1;    
        }

       return {ind1,ind2};

    }
};
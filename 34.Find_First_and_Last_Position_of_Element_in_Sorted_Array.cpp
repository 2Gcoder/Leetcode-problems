class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ind1 = -1 ,ind2 = -1,i,j , st=0 , end = nums.size()-1;
 vector<int> ans;
        while(st <= end) // finding index of first ocurrence of target
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

        for(i= ind1 ;i<nums.size();i++) // from first occurence's index starting loop to find last index of target
        {
            if(nums[i] == target)
                ind2 = i;
        }

       ans.push_back(ind1);
       ans.push_back(ind2);

       return ans;

    }
};
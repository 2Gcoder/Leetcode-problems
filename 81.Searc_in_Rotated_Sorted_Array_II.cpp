class Solution {
public:
    int search(vector<int>& nums, int target) {
        int str=0,end=nums.size()-1,mid;
        mid=str+(end-str)/2;
      
        while(str<=end)
        {  
            
            mid=str+(end-str)/2;
            if(nums[mid]==target)
           { return true;
           break;
           }

           if(nums[mid] == nums[str] && nums[mid] == nums[end]) // similar to previous one(33.sorted array) just add this condition to small the search space 
           {
            str = str +1;
            end = end-1;
            continue;
           }

          if(nums[str]<=nums[mid])  // checking that left side is sorted  
          
          {
          if(nums[str]<=target && target<=nums[mid]) // and target lies between them
            end=mid-1;
            
            else 
             str=mid+1;
            

          }
           
         
         else // or right is sorted or not then again same condition that for target
            {
              if(nums[mid]==target)
              {return true;
              break;}

                if(nums[mid]<=target && target<=nums[end])
                {
                    str=mid+1;
                }

                else
                {
                    end=mid-1;
                }
              }

            }
         
        
      return false;
    }
};
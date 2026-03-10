class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st=1,end = nums.size()-2;
        int n= nums.size();
        if(n==1 || (n==2 && nums[0] > nums[1]))
        return 0;

        if(n==2 && nums[0] < nums[1])
        return 1;


        // Edge case at first and last element 
       if(nums[0] > nums[1]) // first element is graeter then next then it is peak 
       return 0;

       if(nums[n-1] > nums[n-2] ) // last element is greater then second last than itt is peak
       return n-1;
 
       while(st <= end) // Binary search , same approach as to find when single peak  element is given  
       {
       int  mid =(end +st)/2;

        if(nums[mid-1] < nums[mid]  && nums[mid] > nums[mid+1] ) return mid;

        else if(nums[mid] > nums[mid-1]) st = mid +1;

        else end = mid - 1;
       }


    
return -1;

    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i,j;
        int n= nums.size();

        //Edge case for size of array 
        if(n==1 || (n==2 && nums[0] > nums[1]))
        return 0;

        if(n==2 && nums[0] < nums[1])
        return 1;

        for(i=1;i<n-1;i++)
        {
            if(nums[i] > nums[i-1]  && nums[i] > nums[i+1])
                return i ;
        }

// Edge case at first and last element 
       if(nums[0] > nums[1]) // first element is graeter then next then it is peak 
       return 0;

       if(nums[n-1] > nums[n-2] ) // last element is greater then second last than itt is peak
       return n-1;


    
return i;

    }
};
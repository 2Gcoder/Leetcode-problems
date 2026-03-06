class Solution {
public:
    int maxProduct(vector<int>& nums) {

        long int i ,j , result = INT_MIN,pre =1 , suf = 1,n= nums.size();

        for(i=0;i<nums.size();i++)
        {
            if(pre==0) pre=1;
            if(suf == 0) suf=1;

            pre= pre* nums[i]; // multiplication from front till i 
            suf = suf *nums[n-i-1]; // multiplication from back till i 

            result = max(result,max(pre,suf)); 
        }

        return result;
        
    }
};
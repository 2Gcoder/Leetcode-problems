class Solution {
public:
    void sortColors(vector<int>& nums) {
int i,cn0=0,cn1=0,cn2=0;
for(i=0;i<nums.size();i++)
{
    if(nums[i]==0)
    cn0++;

    else{
        if(nums[i]==1)
        cn1++;

        else{
            cn2++;
        }
    }
}

 int index = 0;
        
        while(cn0--!=0) 
        nums[index++] = 0;

        while(cn1--!=0) 
        nums[index++] = 1;

        while(cn2--!=0) 
        nums[index++] = 2;
}

    };
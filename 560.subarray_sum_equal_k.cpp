class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        mpp[0]=1; // in map key'0' pe '1' assign hoga.
        int presum=0;// from index 0 to i tak value ka sum.
     int count=0;
        for(int i=0;i<nums.size();i++)
        {
            presum += nums[i];
            int remove = presum-k;
            count+=mpp[remove];
            mpp[presum]+=1;

        }

        return count;
    }
};

// Explanation link https://youtu.be/xvNwoz-ufXA?si=Q2xz3tA0-dM8NcAQ
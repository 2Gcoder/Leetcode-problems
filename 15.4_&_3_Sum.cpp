class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = 0, k = 0, n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
// 3 pointer approach  ;
// first sort the given array 
// i at first , j is just after the i , k in last
// sum the value of i,j,k 
// if  sum>0 then k-- or sum<0 then j++, because array is sorted
// if sum==0 then k-- and j++ both will changes.
// two extra condition are their  in while below 

        for (i = 0; i < nums.size() - 2; i++) {
            if (i>0 && nums[i] == nums[i - 1])
                continue;

            else {
                j = i + 1;
                k = n - 1;

                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];

                    if (sum > 0) {
                        k--;
                    }

                    else {
                        if (sum < 0) {
                            j++;
                        }

                        else {
     vector<int> temp = {nums[i], nums[j], nums[k]};
                            ans.push_back(temp);
                            j++;
                            k--;
        while (j < k && nums[j] == nums[j - 1])// extra condtion 1
                                j++;

     while (j < k && nums[k] == nums[k + 1]) // Exrta condition 2
                                k--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


 // 4 sum code
 // only two pinter will move remaining makes for loop or they are fixed
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());// sort the given array, we use 4 pointer
        int n =nums.size();
        // only two pinter will move remaining makes for loop or they are fixed
        for (int i = 0; i < n ; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1])// skip duplicate
                continue;

            for (int j = i + 1; j < n ; j++) {
                if (j != (i + 1) && nums[j] == nums[j - 1])// skip duplicate
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];f

                  if(sum==target)
                  {
                      vector<int> temp = {nums[i], nums[j], nums[k],
                                                nums[l]};
                            ans.push_back(temp);
                            k++;
                            l--;

                            while (nums[k] == nums[k - 1] && k<l)
                                k++;
                            while (nums[l] == nums[l + 1] && l>k)
                                l--;
                  }

                  else if(sum>target) l--;
                  else k++; // sum<target
                }
            }
        }

        return ans;
    }
};
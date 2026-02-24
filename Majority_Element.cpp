
//moore's voting algo for element appear more than n/2 time
for(i=0;i<n;i++) 
 {
    if(count==0)
    { count=1;
       el= nums[i];
    }

    else
    {
        if(nums[i]==el)
        count++;
        
        else 
        count--;
    }
 }

 return el;


//  Moore's Voting algo for element appear more than n/3 time
//  SAME AS ABOVE ALGO JUST USE TWO COUNT(CNY1,CNT2) AND TWO EL(EL1,EL2)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && el2 != nums[i]) // checking for count 1 
            {
                cnt1 = 1;
                el1 = nums[i];
            }
             else {
                if (cnt2 == 0 && el1 != nums[i]) // checking for count2 
                {
                    cnt2 = 1;
                    el2 = nums[i];
                }

                else {
                    if (nums[i] == el1) // if both count are false then this else run 
                        cnt1++;

                    else {
                        if (nums[i] == el2)
                            cnt2++;

                        else { // no if is true then both count will decrease. 
                            cnt1--;
                            cnt2--;
                        }
                    }
                }
            }
        }

        vector<int> ls;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }

        int mini = (nums.size() / 3) + 1;
        if (cnt1 >= mini)
            ls.push_back(el1);
        if (cnt2 >= mini)
            ls.push_back(el2);

        return ls;
    }
};
class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {

        int i, j;
        int mini = INT_MAX, maxi = INT_MIN;
        int set = 0, cnt = 0, ans = INT_MAX;




        for (i = 0; i < bd.size(); i++) // taking maximum and minimum value from array , which become the range for binary search 
        {
            maxi = max(maxi, bd[i]);
            mini = min(mini, bd[i]);
        }
        



        while (mini <= maxi) {

           
            int mid = mini + (maxi - mini) / 2;

            for (i = 0; i < bd.size(); i++) {
                if (bd[i] <= mid) // whenever the cnt is break check for no. of set we get for this continous cnt and then  continue. after completing for whole array check for set==m for that paticular mid , according to the value of set change the maxi,mini .
                    cnt++;

                else {
                 if (cnt >= k)
                        set = set + cnt / k;
                    
                         cnt = 0;
                }
            }

             if (cnt >= k)
                        set = set + cnt / k;
                        cnt=0;
                        
                    

           

            if (set >= m && ans > mid)// checking for set , and new mid should less then previous mid which is store in ans . 
            {
               
                ans = mid;
                
                maxi = mid - 1;
            }
            
            
             else
              {  mini = mid + 1;}
            

             set = 0;
        }

        if (ans == INT_MAX)// if we don't get any ans then this .
            return -1;

        return ans;
    }
};
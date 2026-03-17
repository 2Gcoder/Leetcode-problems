class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
     int st = INT_MIN,end=0,sum=0,mid=0,i,day=0,ans=INT_MAX;

     for(i=0;i<weights.size();i++) // range for binary start from max value of array to sum of all element in array
     {
        st = max(st,weights[i]);
        end += weights[i];
     }

     while(st <= end) // we get the range for B.S now apply B.S
     {
        mid=( st + (end-st)/2);
       

        sum=0;
day =0;
        for(i=0;i<weights.size();i++)
        { 
            sum +=weights[i];
            if(sum == mid)
            {
                sum=0;
                day++;
            
            
            }
            else{
                if(sum > mid)
                {
                    sum =0;
                    day++;
                    sum  += weights[i];
                    
                }
            }
        }

        if(sum != 0 && sum <= mid)
            day++;


            if(ans > mid && day <= days)
            {
                ans = mid;
               end = mid - 1;
            }

            else  if(day > days)
                    st = mid +1;
            
            


        
     }
return ans ;

    }
};
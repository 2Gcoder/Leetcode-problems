

int merge(vector<int> &arr, int low,int mid,int high)
{ int cnt =0;
  vector<int> temp ;
   int  left=low;
    int right =mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
     else{
         temp.push_back(arr[right]);
         cnt += (mid - left + 1);  // just add this in merge short , all 
         // remain program is exactly same .
            right++;
          }
        }
    
      while(left<=mid)
      {
        temp.push_back(arr[left]);
        left++;
      }
      
      while(right<=high)
      {
        temp.push_back(arr[right]);
        right++;
      }
    
      for(int m=0;m<temp.size();m++)
      { arr[low+m]=temp[m];

      }

      return cnt;
}


void mergesort(vector<int> &arr,int low,int high)
{ int cnt =0; 

  if(low>=high)
    return cnt;
int mid=(low+high)/2;f

cnt +=  mergesort(arr,low, mid);
 cnt += mergesort( arr,mid+1 , high);
cnt += merge(arr, low,mid,high);

return cnt;
}

int count_the_pairs(vector<int> a ,int n)
{
  return mergesort(a , 0 ,n-1);
 // return of cnt is in merge function

}

// Time complexity if o(n logn)
// Example : arr1={1,3,5,7,8} , arr2={0,2,4,6,9}

// Answer : arr1={0,1,2,3,4} , arr2={5,6,7,8,9}


Class Solution{
    private:
    
        void swapifgreater(long long arr1[],long long arr2[], int index1, int index2)
{
    if(arr1[index1] > arr2[index2])
    {
        swap(arr1[index1] , arr2[index2])
    }
}
    
    
    public: 
void merge(long long arr1[],long long arr2[], int n, int m)
{
    int len=(m+n);
    int gap =(len / 2) - (len % 2);
     

    while(gap > 0)
    {
        int left = 0;
        int right = left -gap;

        while( right < left)
        { // comparing left in arr1 and right in arr2 element
            if(left < n && right >=n)
            {
                 swapifgreater(arr1 ,arr2 ,left ,right-n);
            }

            else{
                // comparing left in arr2 and right in arr2 element 
                if(left >= n)
                {
                    swapifgreater(arr2 ,arr2 ,left - n ,right-n);

                }
               // comparing left in arr1 and right in arr1 element 
                else{
                      swapifgreater(arr1 ,arr1 ,left - m  ,right- m );
                }

            }
left++;
        right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}
}
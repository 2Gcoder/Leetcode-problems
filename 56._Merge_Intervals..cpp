class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
 sort(intervals.begin(),intervals.end());
 
        int n=intervals.size();
        int i=0,j=0,k=0;
        vector<vector<int>> ans;
          vector<int> temp;
   temp.push_back(intervals[0][0]);// starting vector put in temp
   temp.push_back(intervals[0][1]);
   
          for(i=1;i<n;i++)// start from indexing 1 , because previous vector already store in temp. 
          {  j=0;
            
            
            if(intervals[i][j] <= temp[1] ) // for this we already store starting vector in temp .
            {
                k=max(temp[1],intervals[i][j+1]);
                temp[1]=k;
            }

            else{
                ans.push_back(temp);
                temp.clear();
               temp.push_back(intervals[i][j]);
                temp.push_back(intervals[i][j+1]);
                

            }
          }

          ans.push_back(temp);

          return ans ;

    }
};
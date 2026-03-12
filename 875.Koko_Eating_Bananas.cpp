class Solution {
public:

    long long fun(vector<int> &v , long long mid) 
    {
        long long hours = 0;

        for(long long i = 0; i < v.size(); i++)
        {
            hours += (v[i] + mid - 1) / mid;   // ceil division : getting to nearest upper integer.
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long end = 0;

        for(int i = 0; i < piles.size(); i++) // taking the max value form piles . so binary's search space is form 1 to end....
        {
            end = max(end, (long long)piles[i]);
        }

        long long st = 1, mid;

        while(st <= end)
        {
            mid = st + (end - st) / 2;

            long long totaltime = fun(piles, mid); // mid is eating of banana in hour

            if(totaltime <= h) // if it is true we want more smaller mid
                end = mid - 1;
            else
                st = mid + 1;
        }

        return st;
    }
};
#include<bits/stdc++.h>
int subarrayswith5umK(vector<int> a, int k) (
int xr = 0;
map<int,int> mpp:
mpp[xr]++; // {0,1}

int cnt = 0;
for(int i=0;i<a.size();i++) {
int xr = xr ^ a[i];

int x = xr ^ k;

cnt += mppp[x];
mpp[xr]++;
}
return cnt;
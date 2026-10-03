/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1000
Topics: Implementation, Arrays, Frequency Counting
Link: https://codeforces.com/problemset/problem/371/A

Idea:
A k-periodic array means that every position having the same remainder
when divided by k must contain the same value.

For example, if k = 3:

Indices:
0 1 2 3 4 5 6 7 8

Groups:
0: 0 3 6
1: 1 4 7
2: 2 5 8

Each group should become all 1s or all 2s.

For every group, we count:
- How many elements are equal to 1.
- How many elements are equal to 2.

To make the group periodic:
- If we choose value 1, we need to change all 2s.
- If we choose value 2, we need to change all 1s.

Therefore, the minimum changes for each group is:

min(number of 1s, number of 2s)


Approach:
1. Read n and k.
2. Divide the array into k groups based on index modulo k.
3. For each group:
      - Count occurrences of 1 and 2.
      - Add the smaller count to the answer.
4. Print the total minimum number of changes.


Complexity:
Time: O(n) because every array element is visited exactly once.

Auxiliary Space: O(1) because only a fixed-size counter array is used.


*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[200]={0};
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   int ans=0;
   for(int i=0;i<k;i++)
   {
       int cnt[3] = {0};
       for(int j=i;j<n;j+=k)
       {
           cnt[arr[j]]++;
       }
       ans+=min(cnt[1] , cnt[2]);
   }
   cout<< ans;
}

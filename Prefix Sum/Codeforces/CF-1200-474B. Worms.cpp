/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1200
Topics: Prefix Sum
Link: https://codeforces.com/problemset/problem/474/B

Idea:
- Build a prefix sum where pre[i] stores the total number of worms
  from pile 1 to pile i.

- For each queried worm q, find the first prefix value such that:

  pre[i] >= q

- Because the prefix array is increasing, use Binary Search.

- The found index i is the pile containing worm q.

Algorithm:

1. Read the number of worms in each pile.

2. Build prefix sum:

   pre[i] = pre[i-1] + arr[i-1]

3. For every query:

   Binary search for the first index where:

   pre[mid] >= q

4. Print that index.



Complexity:

Building Prefix Sum:
O(N)

Each Query:
O(log N)

Total:
O(N + M log N)

Space:
O(N)

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[100005];
    int pre[100006]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        pre[i] = pre[i-1]+arr[i-1];
    }
    int m;
    cin>>m;
    while(m--)
    {
        int q,ans;
        cin>>q;
        long long l=0,r = 2*n;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(pre[mid]>=q)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout<< ans<< "\n";
    }
}

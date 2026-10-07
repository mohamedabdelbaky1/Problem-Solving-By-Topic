/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1200
Topics: Prefix Sum
Link: https://codeforces.com/problemset/problem/433/B

Idea:
- This is a Prefix Sum + Sorting problem.
- We have two types of queries:

  Type 1:
  Find the sum of stones between l and r in the original order.

  Type 2:
  Sort all stones increasingly, then find the sum between l and r.

Observation:

Both types require range sum queries.

Instead of calculating every query in O(N),
we build prefix sums before answering queries.


For the original array:

prefix[i] = sum of elements from index 1 to i

Algorithm:

1. Read the stones array.

2. Build prefix sum for the original order.

3. Sort the array.

4. Build prefix sum for the sorted array.

5. For every query:

   If type == 1:

       answer using original prefix sum.


   Else:

       answer using sorted prefix sum.



Complexity:

Sorting:
O(N log N)

Building prefix arrays:
O(N)

Each query:
O(1)


Total:
O(N log N + Q)



Space:
O(N)
- Store original prefix sum.
- Store sorted prefix sum.


*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[100005] = {0};
    long long prefix[100005] = {0};
    long long sortedPrefix[100005] = {0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    sort(arr , arr+n);
    for(int i=1;i<=n;i++)
    {
        sortedPrefix[i] = sortedPrefix[i-1] + arr[i-1];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type , left , right;
        cin>>type>>left>> right;
        if(type==1)
            cout<< prefix[right] - prefix[left-1]<< "\n";
        else
            cout<< sortedPrefix[right] - sortedPrefix[left-1]<< "\n";
    }


}

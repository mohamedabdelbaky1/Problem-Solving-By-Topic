/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1200
Topics: Two Pointers
Link: https://codeforces.com/problemset/problem/1006/C

Idea:
- This is a Two Pointers problem.
- We split the array into three contiguous parts:

  first part
  middle part
  third part

- We need:

  sum1 == sum3

- And among all valid splits,
  we want the maximum possible value of sum1.


Observation:

All numbers in the array are positive.

Because of that:

- If left sum is smaller than right sum,
  we can safely move the left pointer forward
  to increase left sum.

- If right sum is smaller than left sum,
  we move the right pointer backward
  to increase right sum.

This allows us to use two pointers instead of checking
all possible splits.

Algorithm:

1. Set:

   l = 0
   r = n-1

   leftSum = 0
   rightSum = 0
   maxi = 0


2. While l <= r:

   If leftSum <= rightSum:

       add arr[l] to leftSum
       move l forward


   Else:

       add arr[r] to rightSum
       move r backward


3. After every move:

   If:

       leftSum == rightSum

   update:

       maxi = leftSum


4. Print maxi.



Complexity:

Time: O(N)

- Each element is processed at most once.
- Left pointer only moves forward.
- Right pointer only moves backward.


Space: O(1)

- No extra data structure is needed.

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int arr[200001] = {0};
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l = 0 , r = n-1;
    long long maxi = 0 , leftsum = 0 , rightsum = 0;
    while(l<=r)
    {
        if(leftsum<=rightsum)
        {
            leftsum+=arr[l];
            l++;
        }
        else if(rightsum<leftsum)
        {
            rightsum+=arr[r];
            r--;
        }
        if(leftsum==rightsum)
            maxi = leftsum;
    }
    cout<< maxi;
}

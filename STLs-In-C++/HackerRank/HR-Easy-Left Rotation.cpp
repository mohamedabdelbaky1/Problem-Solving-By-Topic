/*
Author: Mohamed Abdelbaky Tony
Platform: HackerRank
Rating: Easy
Topics: Arrays
Link: https://www.hackerrank.com/contests/rait-a-thon/challenges/array-left-rotation/problem


Idea:
A left rotation moves every element d positions to the left.
The elements that leave from the left side appear again at the end.

Example:

Array:
[1, 2, 3, 4, 5]

After 2 left rotations:

[3, 4, 5, 1, 2]


Instead of performing the rotation step by step, we can directly construct
the rotated array.

After rotating left by d positions:
- Elements from index d to n-1 move to the front.
- Elements from index 0 to d-1 move to the end.


Approach:
1. Read n (array size) and d (number of left rotations).
2. Store the array elements.
3. Print elements starting from index d until the end.
4. Print the first d elements at the end.
5. The output represents the rotated array.


Complexity:
Time: O(n) because every element is printed exactly once.

Auxiliary Space: O(1) because no additional array is created.

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n , d;
   cin>>n>>d;

   int arr[100001] = {0};

   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }

   for(int i=d;i<n;i++)
   {
       cout<< arr[i]<< " ";
   }

   for(int i=0;i<d;i++)
   {
       cout<<arr[i]<< " ";
   }
}

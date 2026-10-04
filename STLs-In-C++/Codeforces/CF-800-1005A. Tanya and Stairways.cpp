/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Implementation
Link: https://codeforces.com/problemset/problem/1005/A


Idea:
Tanya says numbers while climbing stairs.

For a stairway with x steps, the sequence will be:

1 2 3 ... x

The given array is a concatenation of multiple such sequences.

The end of each stairway can be identified because:
- The next number is smaller than or equal to the current number.
- A new stairway always starts again from 1.

Example:

1 2 3 1 2 3 4

The places where the sequence resets:
    
1 2 3 | 1 2 3 4

The last number before the reset represents the number of steps in that stairway.


Approach:
1. Read the sequence.
2. Traverse the array and check every adjacent pair.
3. If:

       arr[i] >= arr[i+1]

   then arr[i] is the end of a stairway, so store it.

4. The last element of the array is always the end of the final stairway,
   so add it after the loop.
5. Print the number of stairways and their sizes.


Complexity:
Time: O(n) because we traverse the array once.

Auxiliary Space: O(n) because we store the result vector.

In general:
Time : O(n)
Space : O(k) where k is the number of stairways.

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    const int SIZE = n;
    int arr[SIZE];
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>=arr[i+1])
        {
            v.push_back(arr[i]);
        }
    }
        v.push_back(arr[n-1]);
        cout<< v.size()<< "\n";
        for(int i=0;i<v.size();i++)
        {
            cout<< v[i]<< " ";
        }
}

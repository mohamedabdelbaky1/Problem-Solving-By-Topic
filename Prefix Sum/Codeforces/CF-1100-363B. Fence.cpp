/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1100
Topics: Prefix Sum
Link: https://codeforces.com/problemset/problem/363/B

Idea:
- This is a Prefix Sum + Sliding Window problem.
- We need to find exactly k consecutive planks whose total height is minimum.


Observation:

Checking every possible group of k planks

Algorithm:

1. Build prefix sum array.

2. Use a sliding window of size k.

3. For every possible starting index:

   Calculate:

   current sum = prefix[right] - prefix[left]


4. If the current sum is smaller than the minimum:

   Update:
   
   - minimum sum
   - starting index


5. Print the starting index.



Complexity:

Time: O(N)
- Build prefix sum: O(N)
- Check every window once: O(N)


Space: O(N)
- Prefix sum array.

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[150005] ={0};
    long long prefix[150005] = {0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    int l = 0 , r = k;
    long long mini = LLONG_MAX;
    int index = -1;
    while(r<=n)
    {
        if(prefix[r]-prefix[l]<mini)
        {
            mini = prefix[r] - prefix[l];
            index = l+1;
        }
        r++;
        l++;
    }
    cout<< index;
}

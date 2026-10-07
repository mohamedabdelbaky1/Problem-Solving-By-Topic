/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1400
Topics: Partial Sum
Link: https://codeforces.com/problemset/problem/816/B

Idea:
- This is a Difference Array + Prefix Sum problem.
- We have many intervals (recipes).
- Each recipe recommends a temperature range [l, r].
A temperature is admissible if at least k recipes recommend it.
We need to answer many queries:
How many admissible temperatures exist between a and b?

Observation:
Each recipe is a range update.
Instead of increasing every temperature inside the range:
[l, r]
we use a difference array.
Difference Array:
For every recipe:
partialArr[l]++
partialArr[r+1]--

Why?
Because after applying prefix sum:
- The increase starts from l.
- The effect disappears after r.

Example:
Recipes:
91 94
92 97
97 99
For first recipe:
partial[91]++
partial[95]--
After processing all recipes,
prefix sum gives:
temperature -> number of recipes recommending it.

Example:
Temperature:
91 92 93 94 95 96 97 98 99
Number of recipes:
1  2  2  2  1  1  2  1  1
Now we check:
If count >= k:
temperature is admissible.
Convert it to:
1 -> admissible
0 -> not admissible

After that:
We build another prefix sum over admissible temperatures.
Now every query:
[a,b]
can be answered in O(1):
answer = prefix[b] - prefix[a-1]

Algorithm:
1. Create difference array.
2. For every recipe:
   partialArr[l]++
   partialArr[r+1]--
3. Build prefix sum to get how many recipes cover
   every temperature.
4. Convert every temperature:
   if coverage >= k:
       1
   else:
       0
5. Build prefix sum over these binary values.
6. For every query:
   return:
   finalPrefix[b] - finalPrefix[a-1]

Complexity:
Let MAX = 200000
Time: O(MAX + N + Q)
N = number of recipes
Q = number of queries
- Process all intervals once.
- Build prefix arrays once.
- Answer each query in O(1).

Space:
O(MAX)
- Store difference array.
- Store prefix arrays.

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
    int arr[200005] = {0};
    long long partialArr[200005] = {0};
    long long prefixArr[200005] = {0};
    long long finalpre[200005] = {0};
int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        partialArr[l]++;
        partialArr[r+1]--;
    }
    for(int i=0;i<=200002;i++)
    {
        prefixArr[i] = prefixArr[i-1] + partialArr[i-1];
    }
    for(int i=0;i<=200002;i++)
    {
        if(prefixArr[i]<k)
            prefixArr[i] = 0;
        else
            prefixArr[i] = 1;
    }
    for(int i=1;i<=200002;i++)
    {
        finalpre[i] = finalpre[i-1] + prefixArr[i-1];
    }
   while(q--)
   {
       int a,b;
       cin>>a>>b;
       cout<< finalpre[b+2] - finalpre[a+1]<< "\n";
   }
}

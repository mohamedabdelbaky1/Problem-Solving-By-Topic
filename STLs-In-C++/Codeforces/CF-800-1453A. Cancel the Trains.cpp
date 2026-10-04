/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Set, Implementation
Link: https://codeforces.com/problemset/problem/1453/A


Idea:
There are two groups of trains:

1. Trains starting from the bottom side.
2. Trains starting from the left side.

A crash happens when:
- A bottom train with number x
- A left train with number x

meet at the same point at the same time.

The important observation:

A train number uniquely identifies the time/location where a collision can happen.

If the same train number appears in both groups,
there will be one collision.

Therefore:
The minimum number of trains to cancel equals:

(number of bottom trains + number of left trains)
-
(number of unique train numbers)


Approach:
1. Create a set to store all train numbers.

2. Insert all bottom trains into the set.

3. Insert all left trains into the same set.

4. The set keeps only unique train numbers.

5. The number of duplicated train numbers is:

       n + m - set.size()

6. Print the result.

Complexity:

Let:
n = number of bottom trains
m = number of left trains


Time:
O((n + m) log(n + m))

Reason:
Each insertion into a set costs O(log N).


Space:
O(n + m)

Reason:
The set stores all unique train numbers.


In general:

Time : O((n+m) log(n+m))
Space : O(n+m)

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            int trainNumber;
            cin>>trainNumber;
            s.insert(trainNumber);
        }
        for(int i=0;i<m;i++)
        {
            int trainNumber;
            cin>>trainNumber;
            s.insert(trainNumber);
        }
        cout<< (n+m) - s.size()<< "\n";

    }
}


/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1000
Topics: Implementation, Math
Link: https://codeforces.com/contest/450/problem/A


Idea:
Each child needs a certain number of candies (a[i]).
In every turn, Jzzhu gives m candies to the first child in the queue.

A child will leave the queue after receiving enough candies.

For each child, the number of turns needed to leave is:

ceil(a[i] / m)

The child who leaves last is the child with the maximum number of turns.

If multiple children have the same maximum number of turns, the one with the larger index
will be last because they are processed in their original order in the queue.


Approach:
1. Read n (number of children) and m (candies given each turn).
2. Traverse all children and calculate:
   
      number of rounds = ceil(a[i] / m)

3. Keep track of:
      - The maximum number of rounds.
      - The index of the child having this maximum.

4. When a child has:
      rounds >= current maximum

   update the answer.

   Using >= is important because if two children need the same number of rounds,
   the child with the larger index leaves later.

5. Print the index of the last child.


Complexity:
Time: O(n) because we check every child once.

Auxiliary Space: O(1) because we only store the array and a few variables.

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[105]={0};

    int index = -1;
    int maxCeil = 0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

        if(ceil(arr[i]/(double)m)>=maxCeil)
        {
             maxCeil = ceil(arr[i]/(double)m);
             index = i+1;
        }
    }

    cout<< index;
}


// Another solution 

/*

Approach:
1. Read n and k.
2. Create two deques:
      - d1 stores the remaining candies needed for each child.
      - d2 stores the original indices of the children.

3. While more than one child remains:
      - Check the first child.
      - If his remaining candies are greater than k:
            * Reduce his candies by k.
            * Move him to the back of the queue.
      - Otherwise:
            * Remove him from the queue because he has enough candies.

4. When only one child remains:
      - The remaining index in d2 is the last child to leave.
      - Print it using 1-based indexing.


In general:
Time : O(total number of queue operations)
Space : O(n)

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    deque<int>d1(n),d2;

    for(int i=0;i<n;i++)
    {
        cin>>d1[i];
        d2.push_back(i);
    }

    while(d1.size()!=1)
    {
        if(d1.front()>k)
        {
            d1.front()-=k;

            d1.push_back(d1.front());
            d2.push_back(d2.front());

            d1.pop_front();
            d2.pop_front();
        }
        else
        {
            d1.pop_front();
            d2.pop_front();
        }
    }

    cout<< d2[0]+1;
}

/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1100
Topics: Greedy , math
Link: https://codeforces.com/problemset/problem/1492/B


Idea:
We need to reorder the deck to maximize its order:

    p1 * n^(n-1) + p2 * n^(n-2) + ... + pn * n^0

Because higher positions have much larger weights,
the largest cards should appear as early as possible.

The operation allows taking blocks from the top of the original deck
and placing them on the top of the new deck.

The optimal strategy is:
- Find the maximum remaining card.
- Take the segment starting from its position until the current end.
- Put this segment into the answer.
- Continue with the part before that position.


Approach:
1. Store the cards in the array.

2. Create an index array:
      index[i] = i

   This allows sorting positions without changing the original array.

3. Sort the indices according to their card values in increasing order.

4. Start from the largest card position:
      - Take all cards from this position until the current boundary.
      - Print this segment.
      - Move the boundary to this position.

5. Repeat until all cards are printed.


Why sorting works:
The largest element should have the highest possible position in the result.

By taking the segment beginning at the maximum remaining element,
we place this maximum value before all smaller remaining segments.


Complexity:
Time:
O(n log n)

Reason:
We sort all indices once.

The construction step is O(n) because every card is printed once.


Auxiliary Space:
O(n)

Reason:
We store:
- the array values
- the index array


In general:
Time : O(n log n)
Space : O(n)

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int index[100005];
bool fun(int a,int b)
{
    return arr[a]<arr[b];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            index[i]=i;
        }
        sort(index+1,index+1+n,fun);
        int top = n+1;
        int counter=0;
        int k=n;
        while(counter!=n)
        {
            for(int i=index[k];i<top;i++)
            {
                cout<< arr[i]<< " ";
                counter++;
            }
            if(index[k]<top)
            top = index[k];
            k--;
        }
        cout<< "\n";
    }
}

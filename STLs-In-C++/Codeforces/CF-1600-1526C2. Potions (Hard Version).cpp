/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1600
Topics: Greedy
Link: https://codeforces.com/problemset/problem/1526/C2

/*
Idea:
We need to select the maximum number of potions while ensuring that the
current health never becomes negative.

The optimal strategy is to initially take every potion. If the health becomes
negative, we must remove one selected potion.

To lose the minimum number of potions, we remove the potion with the smallest
value because it has the worst effect on our health. Removing it gives the
maximum possible recovery.

A min priority queue is used to always remove the most harmful potion quickly.


Approach:
1. Traverse the potions from left to right.
2. Add each potion to the current health sum and insert it into a min heap.
3. If the health becomes negative:
   - Remove the smallest potion from the heap.
   - Subtract its value from the current health.
4. The size of the heap represents the maximum number of potions we can drink.


Complexity:
Time: O(n log n) because each potion is inserted into the heap once and can
be removed once, and each heap operation costs O(log n).

Auxiliary Space: O(n) because the priority queue can store up to n potions.

*/

// Solution :

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[200001] = {0};
    priority_queue<long long , vector<long long> , greater<long long>>pq;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        pq.push(arr[i]);
        while(sum<0)
        {
            sum-=pq.top();
            pq.pop();
        }
    }
    cout<< pq.size();
}

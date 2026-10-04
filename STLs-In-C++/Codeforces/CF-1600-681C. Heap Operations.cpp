/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1600
Topics: Greedy , Constructive algorithm
Link: https://codeforces.com/contest/681/problem/C

Idea:
We are given a sequence of operations on a min heap, but some operations
may be invalid because:
- getMin x requires the minimum value to be exactly x.
- removeMin requires the heap to contain at least one element.

The goal is to add the minimum number of operations to make the whole sequence
valid.

We simulate the operations using a min heap and insert additional operations
whenever the current state of the heap does not satisfy the required condition.

Approach:
1. Maintain a min heap to represent the current heap state.
2. For insert x:
   - Add x to the heap.
   - Store the operation.
3. For removeMin:
   - If the heap is not empty, remove the minimum element.
   - Otherwise, insert 0 first, then remove it.
4. For getMin x:
   - Remove all elements smaller than x because they can never be the minimum.
   - If the heap becomes empty, insert x.
   - If the minimum is greater than x, insert x.
   - Then perform getMin x.
5. Store every original and added operation in the answer list.
6. Print the final valid sequence.

Complexity:
Time: O(n log n) because each heap operation costs O(log n), and every
inserted/removed element is processed at most once.
Auxiliary Space: O(n) because the heap and answer vector store the operations.

In general:
Time : O(n log n)
Space : O(n)
*/

// Solution :

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int , vector<int> , greater<int>>minHeap;
    vector<pair<string , int>>ans;
    while(n--)
    {
        string x;
        cin>>x;
        int Number;
        if(x=="insert"||x=="getMin")
        {
            cin>>Number;
        }
        if(x=="insert")
        {
            minHeap.push(Number);
            ans.push_back({x , Number});
        }
        else if(x=="removeMin")
        {
            if(!minHeap.empty())
            {
                minHeap.pop();
                ans.push_back({x , 0 });
            }
            else
            {
                minHeap.push(0);
                ans.push_back({"insert" , 0});
                minHeap.pop();
                ans.push_back({"removeMin" , 0});
            }
        }
        else if(x=="getMin")
        {
            if(!minHeap.empty())
            {
                while(Number>minHeap.top()&&!minHeap.empty())
                {
                    minHeap.pop();
                    ans.push_back({"removeMin",0});
                }
            }
            if(minHeap.empty())
            {
                minHeap.push(Number);
                ans.push_back({"insert" , Number});
                ans.push_back({x , Number});
            }
            else
            {
                if(Number==minHeap.top())
                    ans.push_back({x , Number});
                else
                {
                    minHeap.push(Number);
                    ans.push_back({"insert" , Number});
                    ans.push_back({x , Number});
                }
            }

        }
    }
    cout<< ans.size()<< "\n";
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].first== "removeMin")
            cout<< ans[i].first<< "\n";
        else
            cout<< ans[i].first << " "<< ans[i].second<< "\n";
    }
}

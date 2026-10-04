/*
Author: Mohamed Abdelbaky Tony
Platform: HackerRank
Rating: Medium
Topics: Stack
Link: https://www.hackerrank.com/contests/master/challenges/simple-text-editor/problem


Idea:
We need to implement a simple text editor that supports:

1. Append a string to the end.
2. Delete the last k characters.
3. Print the kth character.
4. Undo the last append/delete operation.

The important observation is:
Undo operations must restore the previous state of the string.

Since operations are performed in reverse order,
we can use a Stack to store the history of operations.

For:
- Append operation:
      Store how many characters were added.
      Undo removes these characters.

- Delete operation:
      Store how many characters were deleted.
      Also store the deleted characters so they can be restored later.


Approach:
1. Maintain a vector<char> as the current text.

2. Maintain a stack "Operations":
      It stores the type of the last update operation:
      - Type 1: append operation + number of added characters.
      - Type 2: delete operation + number of deleted characters.

3. Maintain another stack "undo":
      It stores deleted characters from delete operations.

4. Process each operation:

   Type 1 (Append):
      - Add characters to the vector.
      - Store operation details in Operations stack.

   Type 2 (Delete):
      - Remove the last k characters.
      - Before removing, save them in undo stack.
      - Store operation details.

   Type 3 (Print):
      - Print the kth character from the current text.

   Type 4 (Undo):
      - Check the last operation:
          * If it was append:
                Remove the added characters.
          * If it was delete:
                Restore the deleted characters from undo stack.


Complexity:
Let n be the total number of characters modified.

Time:
O(n) because every character is inserted or removed a limited number of times.

Auxiliary Space:
O(n) because we store operation history and deleted characters.


In general:
Time : O(total number of characters affected by operations)
Space : O(total number of characters stored in history)

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int op;
    vector<char>v;
    stack<pair<int,int>>Operations;
    stack<char>undo;
    while(t--)
    {
        cin>>op;
        if(op==1)
        {
            string x;
            cin>>x;
            for(int i=0;i<x.size();i++)
            {
                v.push_back(x[i]);
            }
            Operations.push({1,x.size()});
        }
        else if(op==2)
        {
            int n;
            cin>>n;
            int k=n;
            int start = v.size()-1;
            while(k--)
            {
                undo.push(v[start]);
                v.pop_back();
                start--;
            }
            Operations.push({2,n});
        }
        else if(op==3)
        {
            int n;
            cin>>n;
            cout<< v[n-1]<< "\n";
        }
        else if(op==4)
        {
            if(Operations.top().first==1)
            {
                int turns = Operations.top().second;
                while(turns--)
                {
                    v.pop_back();
                }
                Operations.pop();
            }
            else if(Operations.top().first==2)
            {
                int turns = Operations.top().second;
                while(turns--)
                {
                    v.push_back(undo.top());
                    undo.pop();
                }
                Operations.pop();
            }
        }
    }
}

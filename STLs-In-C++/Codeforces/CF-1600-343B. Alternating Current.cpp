/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1600
Topics: Stack, Greedy, Strings
Link: https://codeforces.com/problemset/problem/343/B


Idea:
The wires are represented by a sequence of characters:

'+' → plus wire is above the minus wire
'-' → minus wire is above the plus wire

The wires can be untangled if every crossing can be cancelled.

A crossing with the same direction appearing twice in a row can be removed:

Example:

++
or

--

means the wire crosses and returns back, so they cancel each other.

The problem is equivalent to checking whether the sequence can be completely reduced
by removing adjacent equal characters.

If nothing remains, the wires are not tangled.


Approach:
1. Create an empty stack.
2. Traverse the string character by character.

3. For each character:
      - If the stack is empty:
            Push the character.
      - Otherwise:
            If the current character equals the stack top:
                  Remove the top element (they cancel).
            Else:
                  Push the current character.

4. After processing all characters:
      - If the stack is empty:
            The wires can be untangled → "Yes".
      - Otherwise:
            Some crossings remain → "No".


Complexity:
Time: O(n) because every character is processed once.

Auxiliary Space: O(n) because the stack can contain all characters in the worst case.

In general:
Time : O(n)
Space : O(n)


Pattern:
Removing Adjacent Pairs

Key Insight:
Whenever a problem asks about:
- cancelling matching elements
- removing neighboring duplicates
- reducing a sequence

Think:
Stack (LIFO)

The stack keeps the remaining unmatched characters.
*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin>>x;
    stack<char>s;
    for(int i=0;i<x.size();i++)
    {
        if(s.empty())
            s.push(x[i]);
        else
        {
            if(x[i]==s.top())
                s.pop();
            else
                s.push(x[i]);
        }
    }
    if(s.empty())
        cout<< "Yes";
    else
        cout<< "No";
}

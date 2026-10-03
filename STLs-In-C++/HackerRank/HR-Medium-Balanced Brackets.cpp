/*
Author: Mohamed Abdelbaky Tony
Platform: HackerRank
Rating: Medium
Topics: Stack, String, Implementation
Link: https://www.hackerrank.com/contests/master/challenges/balanced-brackets/problem

Idea:
A bracket sequence is balanced if:
1. Every opening bracket has a matching closing bracket.
2. The order of brackets is correct.
3. Nested brackets are also balanced.

Examples:

Balanced:
{[()]}

Not Balanced:
{[(])}

The main observation is:
The most recent opening bracket must be closed first.

This follows the LIFO (Last In First Out) rule,
which is exactly what a Stack provides.


Approach:
1. Read the number of test cases.
2. For each bracket string:
      - Create an empty stack.
      - Traverse the string character by character.

3. If the character is an opening bracket:
      - Push it into the stack.

4. If the character is a closing bracket:
      - If the stack is empty:
            There is no matching opening bracket → "NO".
      - Otherwise:
            Check if the top of the stack is the matching opening bracket.
            If yes, remove it using pop().
            If no, the brackets are mismatched → "NO".

5. After processing the whole string:
      - If the stack is empty, all brackets were matched → "YES".
      - Otherwise, there are unmatched opening brackets → "NO".


Complexity:
Time: O(n) for each string because we visit every bracket once.

Auxiliary Space: O(n) in the worst case because the stack can store all opening brackets.

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
        string x;
        int flag=0;

        cin>>x;

        stack<char>st;

        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='('||x[i]=='{'||x[i]=='[')
            {
                st.push(x[i]);
            }
            else
            {
                if(st.empty())
                {
                    cout<< "NO\n";
                    flag=1;
                    break;
                }
                else
                {
                    if(x[i]==')'&&st.top()=='(')
                        st.pop();

                    else if(x[i]=='}'&&st.top()=='{')
                        st.pop();

                    else if(x[i]==']'&&st.top()=='[')
                        st.pop();

                    else
                    {
                        cout<< "NO\n";
                        flag=1;
                        break;
                    }
                }
            }
        }

        if(flag==0)
        {
            if(st.empty())
                cout<< "YES\n";
            else
                cout<< "NO\n";
        }
    }
}

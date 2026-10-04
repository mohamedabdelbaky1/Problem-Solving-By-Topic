/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1200
Topics: Stack, Hashing , Constructive algorithm
Link: https://codeforces.com/problemset/problem/637/B

Idea:
The final order of chats depends on the last message sent to each friend.
The last occurrence of a friend in the messages determines their position
at the top of the chat list.

Therefore, we process the messages in reverse order and keep only the first
occurrence of each friend.

Approach:
1. Store all messages inside a stack to process them from the end.
2. Use a map to mark friends that have already appeared.
3. Pop messages from the stack:
   - If the friend is not visited, print the name and mark it visited.
   - Otherwise, ignore it.

Complexity:
Time: O(n log n) because each map operation costs O(log n)
Auxiliary Space: O(n) because the stack and map store up to n elements

In general:
Time : O(n log n) using ordered map
Space : O(n)
*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
   int n;
   cin>>n;
   stack<string>st;
   map<string,int>m;
   for(int i=0;i<n;i++)
   {
       string x;
       cin>>x;
       st.push(x);
    }
    while(!st.empty())
    {
        if(m[st.top()]==0)
        {
            m[st.top()]++;
            cout<< st.top()<<"\n";

        }
        st.pop();
    }

}

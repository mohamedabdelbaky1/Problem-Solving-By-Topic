/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1400
Topics: Data Structure, Simulation
Link: https://codeforces.com/problemset/problem/1468/C


Idea:
There are two ways to choose a customer:

1. Monocarp:
   - Serves the customer who arrived first.
   - This is a normal queue behavior.

2. Polycarp:
   - Serves the customer with the maximum money value.
   - If multiple customers have the same value, choose the one who arrived first.

To support both operations efficiently, we maintain two ordered sets:
- One set sorted by customer id to get the oldest customer quickly.
- One set sorted by money value and id to get the richest customer quickly.

Each customer is stored in both sets, and whenever a customer is served,
we remove them from both sets.


Approach:
1. Give every customer a unique id according to arrival order.
2. Store customers in:
   
   s1:
   - Sorted by {id, money}
   - Used for Monocarp (type 2).

   s2:
   - Sorted by {money, -id}
   - Used for Polycarp (type 3).
   - Using -id makes older customers come first when money values are equal.

3. For query type 1:
   - Insert the new customer into both sets.

4. For query type 2:
   - Take the first element from s1.
   - This is the earliest customer.
   - Remove it from both sets.

5. For query type 3:
   - Take the last element from s2.
   - This is the customer with maximum money.
   - Remove it from both sets.

6. Store the served customer ids and print them.


Complexity:
Time: O(q log q) because every insertion and deletion from set costs O(log q)

Auxiliary Space: O(q) because the sets store all active customers

In general:
Time : O(n log n)
Space : O(n)
*/

// Solution :

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    set<pair<int,int>>s1,s2;
    int id=1;
    pair<int,int>temp;
    vector<int>ans;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            s1.insert({id,x});
            s2.insert({x,-id});
            id++;
        }
        else if(op==2)
        {
            auto it = s1.begin();
            temp  = {it->second,-it->first};
            ans.push_back(it->first);
            s1.erase(it);
            s2.erase(temp);
        }
        else
        {
            auto it = s2.end();
            it--;
            temp = {-it->second,it->first};
            ans.push_back(-it->second);
            s2.erase(it);
            s1.erase(temp);
        }
    }
        for(auto i:ans)
            cout<< i<< " ";

}

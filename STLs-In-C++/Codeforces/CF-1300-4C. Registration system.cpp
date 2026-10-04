/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1300
Topics: Hashing
Link: https://codeforces.com/contest/4/problem/C


Idea:
The registration system receives usernames one by one.

For every username:
- If it does not exist before:
      Register it and print "OK".

- If it already exists:
      Generate a new unique username by adding a number:
      
          name1, name2, name3, ...

      The number represents how many times this name appeared before.


The problem is simply maintaining the frequency of each username.

We use an unordered_map:

username -> count

to store how many times each username has been registered.


Approach:
1. Create an unordered_map to store username frequencies.

2. For each registration request:

      Case 1:
      Username is not found in the database:
          - Insert it with count = 1.
          - Print "OK".

      Case 2:
      Username already exists:
          - Print username + current count.
          - Increase its counter.


Complexity:

Let:
t = number of registration requests
L = average username length
U = number of unique usernames


Time:
O(t * L) average

Reason:
Each request performs an unordered_map operation.
Hashing a string requires O(L).


Space:
O(U * L)

Reason:
The unordered_map stores every unique username and its counter.


In general:

Time : O(t * L)
Space : O(U * L)

*/


// Solution:


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    unordered_map<string,int>database;
    while(t--)
    {
        string request;
        cin>>request;
        if(database.empty())
        {
            database[request] = 1;
            cout<< "OK\n";
        }
        else
        {
            if(database.find(request)==database.end())
            {
                 database[request] = 1;
                 cout<< "OK\n";
            }
            else
            {
                cout<< request<<database[request]<<"\n";
                database[request]++;
            }
        }
    }
}

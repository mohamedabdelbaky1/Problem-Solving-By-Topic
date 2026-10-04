/*
Author: Mohamed Abdelbaky Tony
Platform: HackerRank
Rating: Easy
Topics: Set, Hashing, Strings
Link: https://www.hackerrank.com/contests/101hack19/challenges/two-strings/problem


Idea:
We need to determine if two strings share at least one common substring.

A substring can be as small as one character.

Therefore, the problem becomes:

"Do the two strings have at least one common character?"

Approach:
1. Store all unique characters of the first string in a set.

2. Store all unique characters of the second string in another set.

3. Merge both sets into a third set.

4. Compare:

      size(set1) + size(set2)

   with:

      size(merged set)


If there is a common character:

Before merging:
- duplicated characters are counted twice.

After merging:
- duplicated characters appear once.


Therefore:

merged.size() < set1.size() + set2.size()

means there is an intersection.

Print:
YES


Otherwise:
NO


Complexity:

Let:
n = length of first string
m = length of second string


Time:
O((n + m) log 26)

Because:
- We insert characters into sets.
- The alphabet size is only 26.

Since 26 is constant:

Time ≈ O(n + m)


Space:
O(26)

Because:
The sets can only contain lowercase English letters.


In general:

Time : O(n + m)
Space : O(1)

*/


// Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
       string x,y;
       cin>>x>>y;
       set<char>s1,s2;
       for(int i=0;i<x.size();i++)
       {
           s1.insert(x[i]);
       }
       for(int i=0;i<y.size();i++)
       {
           s2.insert(y[i]);
       }
       long long Size = s1.size() + s2.size();
       set<char>merged;
       for(auto i:s1)
       {
           merged.insert(i);
       }
       for(auto i:s2)
       {
           merged.insert(i);
       }
       if(merged.size()!=Size)
        cout<< "YES\n";
       else
        cout<< "NO\n";
   }
}

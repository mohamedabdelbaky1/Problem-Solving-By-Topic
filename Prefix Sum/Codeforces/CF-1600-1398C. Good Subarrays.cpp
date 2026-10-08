/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 1600
Topics: Prefix Sum
Link: https://codeforces.com/problemset/problem/1398/C

Idea:
- This is a Prefix Sum + HashMap problem.
- A subarray is good if:

  sum of elements = length of subarray


Transformation:

For a subarray from l to r:

a[l] + a[l+1] + ... + a[r] = r - l + 1


Move the length to the left side:

(a[l] - 1) + (a[l+1] - 1) + ... + (a[r] - 1) = 0


So we transform every digit:

digit -> digit - 1


Now the problem becomes:

Count subarrays whose sum = 0.

Algorithm:

1. Read the string of digits.

2. Create a HashMap:
   prefix sum -> frequency

3. Initialize:
   mp[0] = 1
   because the empty prefix has sum 0.

4. Traverse every digit:
   digit = x[i] - '0'
   sum += digit - 1

5. If this prefix sum appeared before:
   ans += mp[sum]


6. Increase its frequency:
   mp[sum]++

7. Print ans.





Complexity:

For each test case:

Time: O(N)

- Traverse the string once.
- HashMap operations are O(1) average.


Space: O(N)

- HashMap can store up to O(N) different prefix sums.

*/

// Solution : 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string x;
        cin>>x;

        unordered_map<int , long long>mp;
        mp[0] = 1;
        long long sum = 0 , ans = 0;
        for(int i=0;i<n;i++)
        {
            int digit = x[i] - '0';
            sum+=digit - 1;
            if(mp.count(sum))
                ans+=mp[sum];
            mp[sum]++;
        }
        cout<< ans<< "\n";
    }
}


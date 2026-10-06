/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Medium
Topics: Partial Sum
Link: https://leetcode.com/problems/corporate-flight-bookings/description/

Idea:
- This is a Difference Array (Partial Sum) problem.
- We have many range updates:
  
  Add seats to all flights from first to last.

- Instead of updating every flight in the range (which is slow),
  we use a difference array to apply updates efficiently.


Difference Array:

For a range update:

[first, last, seats]


We do:

partialSum[first] += seats

partialSum[last + 1] -= seats


Why?

Because when we build the prefix sum later:

- The addition starts affecting flights from first.
- The subtraction removes the effect after last.

Algorithm:

1. Create difference array (partialSum).
2. For every booking:
   
   Start range:
   partialSum[first-1] += seats

   End range:
   partialSum[last] -= seats


3. Convert difference array into actual values using prefix sum.
4. Remove the extra element.
5. Return the result.


Complexity:

Time: O(N + M)

- M = number of bookings.
- N = number of flights.

Each booking is processed once.
Prefix sum is calculated once.


Space: O(N)

- Store partial sum and result arrays.

*/

// Solution : 

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>partialSum(n+1);
        vector<int>prefixSum(n+1);
        for(int i=0;i<bookings.size();i++)
        {
            partialSum[bookings[i][0]-1]+=bookings[i][2];
            partialSum[bookings[i][1]]-=bookings[i][2];
        }
        prefixSum[0] = partialSum[0];
        for(int i=1;i<n+1;i++)
        {
            prefixSum[i] = prefixSum[i-1] + partialSum[i];
        }
        prefixSum.pop_back();
        return prefixSum;
    }
};

/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Medium
Topics: Partial Sum
Link: https://leetcode.com/problems/car-pooling/description/

Idea:
- This is a Difference Array (Partial Sum) problem.
- We have multiple range updates:
  
  Add passengers when the car reaches "from".
  Remove passengers when the car reaches "to".

- Instead of updating every location in the range, we mark only:
  
  Start point  -> add passengers
  End point    -> remove passengers

- Then we use Prefix Sum to know the current number of passengers
  at every location.


Difference Array:

For every trip:

[passengers, from, to]


We do:

diff[from] += passengers

diff[to] -= passengers


Because passengers leave at "to" before new passengers enter
at the same location.

Algorithm:

1. Create difference array.

2. For every trip:

   Add passengers at the starting location.

   Remove passengers at the ending location.


3. Convert difference array into current passengers
   using prefix sum.

4. If passengers exceed capacity at any point:
   
   return false.


5. Otherwise return true.



Complexity:

Time: O(N + M)

N = number of locations

M = number of trips


- Process every trip once.
- Build prefix sum once.


Space: O(N)

- Store difference array.



*/

// Solution : 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> diff(1001);


        for(auto &trip : trips)
        {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }


        int passengers = 0;


        for(int i=0;i<=1000;i++)
        {
            passengers += diff[i];

            if(passengers > capacity)
                return false;
        }


        return true;
    }
};

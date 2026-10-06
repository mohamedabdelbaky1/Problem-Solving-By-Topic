/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Medium
Topics: Prefix Sum
Link: https://leetcode.com/problems/subarray-sum-equals-k/description/

Idea:
- This is a Prefix Sum + HashMap problem.
- We need to count the number of continuous subarrays whose sum equals k.

Instead of storing all prefix sums, we calculate the prefix sum while
traversing the array.


Key Observation:

For any subarray:

sum(L,R) = prefix[R] - prefix[L-1]


We need:

prefix[R] - prefix[L-1] = k


Rearrange:

prefix[L-1] = prefix[R] - k


Meaning:

For every current prefix sum, we check if we have seen a previous
prefix sum equal to:

current sum - k


If it exists:
- Every occurrence represents a valid subarray.


Algorithm:

1. Create a HashMap to store:
   
   prefix sum -> frequency

2. Initialize:

   mp[0] = 1

   because a subarray can start from index 0.


3. Traverse the array:

   - Add current element to the running sum.
   
   - Check if:
     
     sum - k

     exists in the map.

   - If yes, add its frequency to the answer.

   - Store the current sum in the map.


Complexity:

Time: O(N)

- We traverse the array once.
- HashMap operations are O(1) average.


Space: O(N)

- HashMap stores all possible prefix sums.
*/

// Solution : 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int ans=0;
        int sum = 0;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.count(sum-k))
            {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};

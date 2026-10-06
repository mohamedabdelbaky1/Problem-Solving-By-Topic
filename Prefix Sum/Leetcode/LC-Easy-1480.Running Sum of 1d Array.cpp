/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Easy
Topics: Prefix Sum
Link: https://leetcode.com/problems/running-sum-of-1d-array/description/

Idea:
- This is a Prefix Sum problem.
- Each element stores the sum of itself and all previous elements.

Algorithm:
1. Start from index 1.
2. Add the previous prefix sum to the current element.
3. Return nums.

Complexity:
Time: O(N)
Space: O(1)

*/

// Solution : 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i-1];
        }

        return nums;
    }
};

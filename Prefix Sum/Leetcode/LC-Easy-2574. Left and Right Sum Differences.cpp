/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Easy
Topics: Prefix Sum
Link: https://leetcode.com/problems/left-and-right-sum-differences/description/

Idea:
- This is a Prefix Sum problem.
- For every index, we need:
  
  answer[i] = |Left Sum - Right Sum|

- Instead of calculating the left and right sums every time,
  we build a prefix sum array.

Algorithm:

1. Create prefix sum array.
2. Build prefix array:
   
   prefix[i] = prefix[i-1] + nums[i-1]

3. Traverse each index:
   
   Calculate left sum:
   prefix[i-1]

   Calculate right sum:
   prefix[n-2] - prefix[i]

4. Store:
   
   abs(leftSum - rightSum)

5. Return answer array.


Complexity:

Time: O(N)

- Build prefix array: O(N)
- Calculate differences: O(N)


Space: O(N)

- Prefix array storage.
- Answer array storage.

*/

// Solution : 

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size()+2;
        vector<int>prefix(n);
        vector<int>ans;
        for(int i=1;i<n-1;i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int RightSum = 0 , LeftSum = 0;
        for(int i=1;i<=nums.size();i++)
        {
            RightSum = prefix[n-2] - prefix[i];
            LeftSum  = prefix[i-1];
            ans.push_back(abs(LeftSum - RightSum));
        }
        return ans;
    }
};

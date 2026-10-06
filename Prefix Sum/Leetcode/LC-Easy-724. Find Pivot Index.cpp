/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Easy
Topics: Prefix Sum
Link: https://leetcode.com/problems/find-pivot-index/description/

Idea:
- This is a Prefix Sum problem.
- We need to find an index where:
  
  Sum of elements on the left == Sum of elements on the right

- Instead of recalculating the left and right sums for every index,
  we build a prefix sum array.

Algorithm:

1. Create prefix sum array.
2. Store cumulative sum of elements.
3. For every index:
   
   Left Sum:
   prefixSum[i]

   Right Sum:
   Total Sum - prefixSum[i+1]

4. If left sum equals right sum, return the index.
5. If no pivot exists, return -1.


Complexity:

Time: O(N)

- Build prefix array: O(N)
- Check every index: O(N)


Space: O(N)

- We store the prefix sum array.
*/

// Solution : 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int n = nums.size() + 2;
         vector<int>prefixSum(n);

        for(int i=1;i<n-1;i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        int ans  = -1;
        int RightSum = 0 , LeftSum = 0;
        for(int i=1;i<=nums.size();i++)
        {
            RightSum = prefixSum[n-2] - prefixSum[i];
            LeftSum  = prefixSum[i-1];
            if(RightSum==LeftSum)
            {
                ans = i-1;
                return ans;
            }
        }
        return ans;
    }
};

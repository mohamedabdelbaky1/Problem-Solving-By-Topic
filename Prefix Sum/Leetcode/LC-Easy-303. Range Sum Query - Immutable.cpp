/*
Author: Mohamed Abdelbaky Tony
Platform: Leetcode
Rating: Easy
Topics: Prefix Sum
Link: https://leetcode.com/problems/range-sum-query-immutable/description/

Idea:
- This is a Prefix Sum problem.
- We need to answer multiple range sum queries efficiently.
- Instead of calculating the sum every time, we build a prefix array once.

Algorithm:

1. Create prefix array of size n + 1.
2. Initialize prefix[0] = 0.
3. Build prefix array:
   
   prefix[i+1] = prefix[i] + nums[i]

Complexity:

Constructor:
Time: O(N)
- We iterate over nums once.

Query:
Time: O(1)
- Only two prefix accesses.

Space:
O(N)
- We store the prefix array.

*/

// Solution : 

class NumArray {
private:
    vector<int> prefix;

public:

    NumArray(vector<int>& nums) {

        int n = nums.size();

        prefix.resize(n + 1);

        prefix[0] = 0;


        for(int i = 0; i < n; i++)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }
    }


    int sumRange(int left, int right) {

        return prefix[right + 1] - prefix[left];

    }
};

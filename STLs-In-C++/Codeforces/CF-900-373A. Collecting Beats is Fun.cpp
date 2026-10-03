/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 900
Topics: Implementation, Hashing, Frequency Counting
Link: https://codeforces.com/problemset/problem/373/A

Idea:
The boy can press at most k panels with one hand.
Since he has two hands, he can press at most 2*k panels at the same time.

For every digit from 1 to 9, we need to count how many times it appears
in the 4x4 panel.

If any digit appears more than 2*k times, then he cannot press all panels
of that time simultaneously, so the answer is "NO".

Otherwise, he can press all panels perfectly, so the answer is "YES".


Approach:
1. Read the value of k.
2. Traverse the 4x4 grid.
3. Count the frequency of each digit using an unordered_map.
4. Check every digit frequency:
      - If frequency > 2*k:
            The required number of presses exceeds his ability.
            Print "NO".
5. If all digits satisfy the condition, print "YES".


Complexity:
Time: O(1) because the grid size is fixed (4x4 = 16 cells)
Auxiliary Space: O(1) because we store at most 9 digits.

*/

// Solution:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    unordered_map<char, int> frequency;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            char c;
            cin >> c;

            if(c != '.')
            {
                frequency[c]++;
            }
        }
    }

    for(auto digit : frequency)
    {
        if(digit.second > 2 * k)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}

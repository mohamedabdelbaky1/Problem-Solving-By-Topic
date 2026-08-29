/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 900
Topics: Implementation
Link: https://codeforces.com/contest/709/problem/A

Idea:
Process the oranges in order.

If an orange is larger than the juicer's maximum allowed size,
ignore it.

Otherwise, add its size to the waste section.
Whenever the accumulated waste becomes greater than d,
empty the waste section and count one overflow.

Approach:
1. Read n, b, and d.
2. Read the sizes of all oranges.
3. Traverse the oranges in order.
4. If the current orange size is less than or equal to b,
   add it to the accumulated waste.
5. If the accumulated waste becomes greater than d:
   - Increment the answer.
   - Reset the accumulated waste to 0.
6. Print the total number of times the waste section was emptied.

Complexity:
Time: O(n)
Auxiliary Space: O(n)
*/

// Solution : 


using System;

namespace ConsoleApp1
{
    internal class Program
    {
        
        static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

            int NumberOfOranges = input[0];
            int MaximumSize = input[1];
            int WasteConditionSize = input[2];

            int[] OrangeSizes = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int TotalSize = 0;
            int res = 0;
            for(int i=0; i< NumberOfOranges; i++)
            {
                if (OrangeSizes[i] <= MaximumSize)
                {
                    TotalSize += OrangeSizes[i];
                    if (TotalSize > WasteConditionSize)
                    {
                        res++;
                        TotalSize = 0;
                    }
                }
            }
            Console.WriteLine(res);

        }
    }
}
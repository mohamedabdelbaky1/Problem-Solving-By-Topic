/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Implementation, Hashing
Link: https://codeforces.com/contest/228/problem/A

Idea:
Valera needs four horseshoes with different colors.
Therefore, we only need to determine how many distinct colors
he already has.

The number of horseshoes he needs to buy is:
4 - number of distinct colors.

Approach:
1. Read the four horseshoe colors.
2. Insert them into a HashSet to keep only distinct colors.
3. Subtract the number of distinct colors from 4.
4. Print the result.

Complexity:
Time: O(1) because the array is just 4 elements
Auxiliary Space: O(1) because the array is just 4 elements

In general:
Time : O(n) for n elements not just 4
Space : O(n) for n elements not just 4
*/

// Solution : 


using System;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] Colors = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

            HashSet<int> DistinctColors = new HashSet<int>(Colors);
            
            Console.WriteLine( 4 - DistinctColors.Count );


        }
    }
}
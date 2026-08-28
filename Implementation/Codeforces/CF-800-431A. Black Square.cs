/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Implementation
Link: https://codeforces.com/contest/431/problem/A

Idea of the problem:
Each character represents one of the four strips.
Use the character to directly access its corresponding calorie cost.

Approach:
Traverse the string and add the cost of each selected strip
using s[i] - '1' as the array index.

Complexity:
Time: O(n)
Auxiliary Space: O(1)
*/

// Solution : 


using System;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            string s = Console.ReadLine();

            long res = 0;

            for (int i = 0; i < s.Length; i++)
            {
                res += arr[s[i] - '1'];
            }

            Console.WriteLine(res);
        }
    }
}
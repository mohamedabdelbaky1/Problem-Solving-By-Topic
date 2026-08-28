/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Implementation
Link: https://codeforces.com/contest/731/problem/A

Idea:
The alphabet is arranged in a circular wheel of 26 letters.
For each character, calculate the distance from the current position
in both clockwise and counterclockwise directions, then choose the
smaller number of rotations.

Approach:
Start from the letter 'a'.

For each character in the string:
1. Calculate the clockwise and counterclockwise distances.
2. Add the minimum distance to the total number of rotations.
3. Update the current wheel position to the current character.

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
            int n = int.Parse(Console.ReadLine());

            int[] home = new int[n];
            int[] guest = new int[n];

            for(int i=0; i<n;i++)
            {
                int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                home[i] = input[0];
                guest[i] = input[1];
            }
            int res = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (i == j)
                        continue;
                    if (home[i] == guest[j])
                        res++;
                }
            }
            Console.WriteLine(res);
        }
    }
}
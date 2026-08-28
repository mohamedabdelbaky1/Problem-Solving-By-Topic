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
           string x = Console.ReadLine();
            int first = 0, second = 0;
            char MyPosition = 'a';
            long res = 0;
            for(int i= 0; i< x.Length; i++)
            {
                if(MyPosition - x[i] >=0)
                {
                    first = MyPosition - x[i];
                    second = x[i] - MyPosition + 26;
                    res += Math.Min(first, second);
                }
                else
                {
                    first = MyPosition - x[i] +26;
                    second = x[i] - MyPosition;
                    res += Math.Min(first, second);
                }
                MyPosition = x[i];
            }
            Console.WriteLine(res);
        }
    }
}
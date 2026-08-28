/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Strings, Implementation
Link: https://codeforces.com/contest/265/problem/A

Idea:
Liss starts at the first stone.

For each instruction in the second string, compare it with the color
of the stone at the current position.

If the colors match, Liss moves one step forward.
Otherwise, she stays at the same position.

Approach:
1. Start with Index = 0, representing the first stone.
2. Traverse all instructions in the second string.
3. If the current instruction matches x[Index], increment Index.
4. After processing all instructions, print Index + 1 because
   the required answer is 1-based.

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
            string y = Console.ReadLine();
            int Index = 0;

            foreach(char i in y)
            {
                if (i == x[Index])
                    Index++;
            }
            Console.WriteLine(Index+1);
        }
    }
}
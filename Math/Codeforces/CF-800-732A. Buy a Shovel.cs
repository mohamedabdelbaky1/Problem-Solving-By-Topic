/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Math, Brute Force
Link: https://codeforces.com/contest/732/problem/A

Idea:
- We have infinite number of coins(10) and just one coin(r) so we need to calculate the minimum number of shovels we can buy without any change:
- we should solve this equation : ( k * x ) % 10 = r 
- the unkown is x and the givens are ( k ,r ) 
- Be careful : we need the smallest x 

Approach:
Try buying from 1 to 9 shovels.

For each number i:
calculate the cost 

Complexity:
Time: O(1)
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
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int k = input[0];
            int r = input[1];

            for(int i=1;i<=9;i++)
            {
                if( (k * i) % 10 == 0 || (k * i) % 10 == r )
                {
                    Console.WriteLine(i);
                    break;
                }
            }
        }
    }
}
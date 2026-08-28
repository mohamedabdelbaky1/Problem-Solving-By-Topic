/*
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Math, Probability
Link: https://codeforces.com/contest/9/problem/A

Idea:
Dot wins if her die roll is greater than or equal to the maximum
score between Yakko and Wakko.

The number of successful outcomes is therefore the count of values
from max(Yakko, Wakko) to 6.

The probability is represented as:
successful outcomes / 6

Then the fraction is reduced using the Greatest Common Divisor (GCD).

Approach:
1. Read Yakko's and Wakko's scores.
2. Find the maximum of the two scores.
3. Calculate the number of successful outcomes:
   6 - maxScore + 1
4. Set the denominator to 6.
5. Find the GCD of the numerator and denominator using
   the Euclidean Algorithm.
6. Divide both by the GCD to get the irreducible fraction.
7. Print the reduced fraction.

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
        static int GCD(int a , int b)     
        {
            if (b == 0)
                return a;

            return GCD(b, a % b);
        }
        static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int YakkoScore = input[0];
            int WakkoScore = input[1];

            int Numerator = 6 - Math.Max(YakkoScore, WakkoScore) + 1;
            int Denominator = 6;

            int gcd = GCD(Numerator, Denominator);                              // O(log(min(a,b)))
            Console.WriteLine($"{Numerator / gcd}/{Denominator / gcd}");


        }
    }
}
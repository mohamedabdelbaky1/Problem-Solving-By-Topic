
// Author : Mohamed Abdelbaky Tony 
// Topic : Strings 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/59/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int Capital = 0, Small = 0;
            for(int i = 0; i < input.Length; i++)
            {
                if (input[i] <= 90)
                    Capital++;
                else
                    Small++;
            }
            if (Small >= Capital)
                Console.WriteLine(input.ToLower());
            else
                Console.WriteLine(input.ToUpper());
        }
    }
}


// Author : Mohamed Abdelbaky Tony 
// Topic : Strings 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/236/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            int DistinctCount = new HashSet<char>(input).Count();
            if (DistinctCount % 2 == 0)
                Console.WriteLine("CHAT WITH HER!");
            else
                Console.WriteLine("IGNORE HIM!");
        }
    }
}

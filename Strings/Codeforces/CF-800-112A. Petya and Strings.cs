
// Author : Mohamed Abdelbaky Tony 
// Topic : Strings 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/112/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string x = Console.ReadLine();
            string y = Console.ReadLine();

            x = x.ToLower();
            y = y.ToLower();

            int res = string.Compare(x, y);
            Console.WriteLine(res);
        }
    }
}

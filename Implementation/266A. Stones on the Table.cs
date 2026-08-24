
// Author : Mohamed Abdelbaky Tony 
// Topic : Implementation 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/266/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int Counter = 0;
            string x = Console.ReadLine();
            for(int i=1;i<n;i++)
            {
                if (x[i] == x[i - 1])
                    Counter++;
            }
            Console.WriteLine(Counter);
        }
    }
}
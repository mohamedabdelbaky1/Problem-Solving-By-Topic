
// Author : Mohamed Abdelbaky Tony 
// Topic : Greedy 
// Source : Codeforces 
// Rate : 900
// Problem Link : https://codeforces.com/contest/405/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = Array.ConvertAll(Console.ReadLine().Split() ,int.Parse);
            Array.Sort(arr);
            foreach (var item in arr)
            {
                Console.Write($"{item} ");
            }
        }
    }
}

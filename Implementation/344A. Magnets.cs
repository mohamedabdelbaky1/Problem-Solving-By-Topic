
// Author : Mohamed Abdelbaky Tony 
// Topic : Implementation 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/344/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            string[] arr = new string[n];

            for (int i=0; i<n;i++)
            {
                arr[i] = Console.ReadLine();
            }
            int counter = 1;
            for(int i=1;i<n;i++)
            {
                if (arr[i] != arr[i-1])
                {
                       counter++;
                }
            }

            Console.WriteLine(counter);
        }
    }
}
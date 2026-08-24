
// Author : Mohamed Abdelbaky Tony 
// Topic : Implementation 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/677/problem/A

using System.Diagnostics.Metrics;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int[] nh = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int n = nh[0];
            int h = nh[1];

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int Counter = 0;
            for (int i=0;i<n;i++)
            {
                if (arr[i] > h)
                    Counter += 2;
                else
                    Counter++;
            }
            Console.WriteLine(Counter);


        }
    }
}

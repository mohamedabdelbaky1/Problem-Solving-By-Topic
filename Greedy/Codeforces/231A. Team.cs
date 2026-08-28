
// Author : Mohamed Abdelbaky Tony 
// Topic : Greedy 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/231/problem/A
using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[,] arr = new int[n, 3];
            for (int i = 0; i < n; i++)
            {
                int[] values = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);

                for (int j = 0; j < 3; j++)
                    arr[i, j] = values[j];
            }

            int res = 0;
            for(int i=0;i<n;i++)
            {
                int c = 0;
                for (int j=0;j<3;j++)
                {
                    if (arr[i, j] > 0)
                        c++;
                }
                if (c > 1)
                    res++;
            }
            Console.WriteLine(res);

        }
    }
}


// Author : Mohamed Abdelbaky Tony 
// Topic : Implementation 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/263/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[,] Matrix = new int[5, 5];
            int x = 0, y = 0; 
            for (int i = 0;i < 5; i++)
            {
                int[] rows = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                for (int j=0; j<5;j++)
                {
                    Matrix[i, j] = rows[j];
                    if(Matrix[i, j]==1)
                    {
                        x = i;
                        y = j;
                    }
                }
            }
            int res = Math.Abs(x-2) + Math.Abs(y-2);
            Console.WriteLine(res);


        }
    }
}

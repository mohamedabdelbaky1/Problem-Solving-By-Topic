
// Author : Mohamed Abdelbaky Tony 
// Topic : Implementation 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/427/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int flag = 0;
            int crime = 0;
            for (int i = 0; i < n; i++)   // -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1
            {
                if (arr[i]<0)
                {
                    flag--;
                    if(flag<0)
                    {
                        crime++;
                        flag = 0;
                    }
                    
                }
                else
                {
                    flag += arr[i];
                }
            }
            Console.WriteLine(crime);

        }    
    }
}

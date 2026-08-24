
// Author : Mohamed Abdelbaky Tony 
// Topic : Greedy 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/381/problem/A

using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int t = n;
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int p1 = 0, p2 = n - 1;
            int SerejaScore = 0, DimaScore = 0;

            while(t>0)
            {
                if(arr[p1]>=arr[p2])
                {
                    SerejaScore += arr[p1];
                    p1++;
                }
                else
                {
                    SerejaScore += arr[p2];
                    p2--;
                }
                t--;
                if (t == 0)
                    break;
                if(arr[p1]>=arr[p2])                   
                {
                    DimaScore += arr[p1];
                    p1++;
                }
                else
                {
                    DimaScore += arr[p2];
                    p2--;
                }
                t--;
            }
            Console.WriteLine($"{SerejaScore} {DimaScore}");
        }
    }
}

// Author : Mohamed Abdelbaky Tony 
// Topic : Strings 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/734/problem/A
using System.Diagnostics.Metrics;
using System.Xml;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int t = int.Parse(Console.ReadLine());
            string x = Console.ReadLine();
            int A = 0, D = 0;
            foreach(char i in x)
            {
                if (i == 'A')
                    A++;
                else
                    D++;
            }
            if (A > D)
                Console.WriteLine("Anton");
            else if (A < D)
                Console.WriteLine("Danik");
            else
                Console.WriteLine("Friendship");

        }
    }
}


// Author : Mohamed Abdelbaky Tony 
// Topic : Math 
// Source : Codeforces 
// Rate : 800
// Problem Link : https://codeforces.com/contest/791/problem/A

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] Input = Console.ReadLine().Split();
            int a = int.Parse(Input[0]);
            int b = int.Parse(Input[1]);

            Console.WriteLine((int)(Math.Log10((double)b/a) / Math.Log10(3.0/2.0))+1);


        }
    }
}

using System;
using System.IO;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string? Line = Console.ReadLine();
            int n=0, t=0;
            if (Line != null)
            {
                string[] parts = Line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                
                int.TryParse(parts[0], out n);
                int.TryParse(parts[1], out t);
            }
                int[] arr = new int[n];
                string[] p = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
                for(int i=0;i<n;i++)
                {
                    int.TryParse(p[i], out arr[i]);
                }

            int p1 = 0, p2 = 0, sum = 0, ans = 0;
            while(p1<n)
            {
                while (p2 < n && sum + arr[p2]<=t)
                {
                    sum += arr[p2];
                    p2++;
                }
                if(p2-p1>ans)
                {
                    ans = p2 - p1;
                }
                sum -= arr[p1];
                p1++;

            }
            Console.WriteLine(ans);


            
        }
    }
}


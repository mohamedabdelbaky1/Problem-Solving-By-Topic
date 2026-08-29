/*
Problem: Way Too Long Words
Author: Mohamed Abdelbaky Tony
Platform: Codeforces
Rating: 800
Topics: Strings
Link: https://codeforces.com/contest/71/problem/A

Idea:
A word is considered too long if its length is greater than 10.

For every long word, keep the first and last characters and replace
the characters between them with their count.

Approach:
1. Read the number of words.
2. Process each word one by one.
3. If its length is greater than 10:
   - Print the first character.
   - Print the number of characters between the first and last characters.
   - Print the last character.
4. Otherwise, print the word without any changes.

Complexity:
Time: O(n)
Auxiliary Space: O(1)
*/

// Solution : 


using System;
using System.IO;
using System.Text;
using System.Globalization;
using System.Numerics;

namespace ConsoleApp1
{
    internal class Program
    {
       
        static void Main(string[] args)
        {

            FastScanner input = new FastScanner();
            int n = input.NextInt();
            string x;
            for(int i=0;i<n;i++)
            {
                x = input.Next();
                if(x.Length > 10)
                {
                    Console.WriteLine($"{x[0]}{x.Length - 2}{x[x.Length-1]}");
                }
                else
                {
                    Console.WriteLine(x);
                }
            }
            

     

        }
    }






public class FastScanner
    {
        private readonly Stream _stream;
        private readonly byte[] _buffer;
        private int _bufferLength;
        private int _bufferIndex;

        public FastScanner()
        {
            _stream = Console.OpenStandardInput();
            _buffer = new byte[1 << 16]; // 64 KB buffer
        }

        private int ReadByte()
        {
            if (_bufferIndex >= _bufferLength)
            {
                _bufferLength = _stream.Read(_buffer, 0, _buffer.Length);
                _bufferIndex = 0;

                if (_bufferLength == 0)
                    return -1;
            }

            return _buffer[_bufferIndex++];
        }

        private int SkipWhiteSpace()
        {
            int c;

            do
            {
                c = ReadByte();
            }
            while (c != -1 && c <= ' ');

            return c;
        }

        // =========================
        // String
        // =========================

        public string Next()
        {
            int c = SkipWhiteSpace();

            if (c == -1)
                return null;

            StringBuilder sb = new StringBuilder();

            while (c != -1 && c > ' ')
            {
                sb.Append((char)c);
                c = ReadByte();
            }

            return sb.ToString();
        }

        public string NextString()
        {
            return Next();
        }

        // =========================
        // Char
        // =========================

        public char NextChar()
        {
            int c = SkipWhiteSpace();

            if (c == -1)
                throw new EndOfStreamException();

            return (char)c;
        }

        // =========================
        // Signed Integers
        // =========================

        public int NextInt()
        {
            return (int)NextLong();
        }

        public long NextLong()
        {
            int c = SkipWhiteSpace();

            bool negative = false;

            if (c == '-')
            {
                negative = true;
                c = ReadByte();
            }

            long number = 0;

            while (c >= '0' && c <= '9')
            {
                number = number * 10 + (c - '0');
                c = ReadByte();
            }

            return negative ? -number : number;
        }

        public short NextShort()
        {
            return (short)NextInt();
        }

        public sbyte NextSByte()
        {
            return (sbyte)NextInt();
        }

        // =========================
        // Unsigned Integers
        // =========================

        public uint NextUInt()
        {
            return (uint)NextULong();
        }

        public ulong NextULong()
        {
            int c = SkipWhiteSpace();

            ulong number = 0;

            while (c >= '0' && c <= '9')
            {
                number = number * 10 + (ulong)(c - '0');
                c = ReadByte();
            }

            return number;
        }

        public ushort NextUShort()
        {
            return (ushort)NextUInt();
        }

        public byte NextByte()
        {
            return (byte)NextUInt();
        }

        // =========================
        // Floating Point
        // =========================

        public double NextDouble()
        {
            return double.Parse(
                Next(),
                CultureInfo.InvariantCulture
            );
        }

        public float NextFloat()
        {
            return float.Parse(
                Next(),
                CultureInfo.InvariantCulture
            );
        }

        public decimal NextDecimal()
        {
            return decimal.Parse(
                Next(),
                CultureInfo.InvariantCulture
            );
        }

        // =========================
        // Boolean
        // =========================

        public bool NextBool()
        {
            return bool.Parse(Next());
        }

        // =========================
        // BigInteger
        // =========================

        public BigInteger NextBigInteger()
        {
            return BigInteger.Parse(
                Next(),
                CultureInfo.InvariantCulture
            );
        }

        // =========================
        // Arrays
        // =========================

        public int[] NextIntArray(int n)
        {
            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
                arr[i] = NextInt();

            return arr;
        }

        public long[] NextLongArray(int n)
        {
            long[] arr = new long[n];

            for (int i = 0; i < n; i++)
                arr[i] = NextLong();

            return arr;
        }

        public double[] NextDoubleArray(int n)
        {
            double[] arr = new double[n];

            for (int i = 0; i < n; i++)
                arr[i] = NextDouble();

            return arr;
        }

        public string[] NextStringArray(int n)
        {
            string[] arr = new string[n];

            for (int i = 0; i < n; i++)
                arr[i] = Next();

            return arr;
        }
    }





}
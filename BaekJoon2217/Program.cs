using System;
using System.Collections.Generic;

namespace BaekJoon2217
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            List<int> input = new List<int>();
            int max = 0;
            int curMax = 0;

            for (int i = 0; i < n; i++)
            {
                input.Add(int.Parse(Console.ReadLine()));
            }

            input.Sort();

            for (int j = 0; j < n; j++)
            {
                curMax = input[j] * (n - j);
                max = curMax > max ? max = curMax : max;
            }

            Console.WriteLine(max);
        }
    }
}

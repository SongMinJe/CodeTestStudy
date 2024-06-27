using System;

namespace BeakJoon1789
{
    internal class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long sum = 0;
            long i = 0;
            long result = 0;
            while (sum < n)
            {
                i++;
                sum += i;
                if (sum > n)
                {
                    break;
                }
                else
                {
                    result++;
                }
            }
            Console.WriteLine(result);
        }
    }
}

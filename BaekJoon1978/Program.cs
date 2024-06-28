using System;

namespace BaekJoon1978
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] nums = Console.ReadLine().Split(' ');
            int[] inputs = Array.ConvertAll(nums, int.Parse);
            int result = 0;

            foreach (var num in inputs)
            {
                if (num > 1)
                {
                    bool isPrime = true;
                    for (int i = 2; i < num; i++)
                    {
                        if (num % i == 0)
                        {
                            isPrime = false;
                            break;
                        }
                    }
                    if (isPrime == true)
                    {
                        result++;
                    }
                }
            }
            Console.WriteLine(result);
        }
    }
}

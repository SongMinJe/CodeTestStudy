using System;

namespace BaekJoon5585
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] coin = { 500, 100, 50, 10, 5, 1 };
            int input = int.Parse(Console.ReadLine());
            input = 1000 - input;
            int result = 0;

            for (int i = 0; i < coin.Length; i++)
            {
                if (coin[i] <= input)
                {
                    result += input / coin[i];
                    input %= coin[i];
                }
            }
            Console.WriteLine(result);
        }
    }
}

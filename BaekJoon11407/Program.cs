using System;

namespace 백준
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] splitBase = Console.ReadLine().Split(' ');
            int n = int.Parse(splitBase[0]);
            int k = int.Parse(splitBase[1]);
            int result = 0;

            List<int> coin = new List<int>();

            for (int i = 0; i < n; i++)
            {
                coin.Add(int.Parse(Console.ReadLine()));
            }

            coin.Reverse();

            for (int j = 0; j < coin.Count; j++)
            {
                if (k < coin[j])
                {
                    continue;
                }
                result += k / coin[j];
                k %= coin[j];
            }

            Console.Write(result);
        }
    }
}
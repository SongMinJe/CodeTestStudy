using System;
using System.IO;
using System.Numerics;

namespace BaekJoon1010
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int caseNum = int.Parse(reader.ReadLine());
            BigInteger result = 0;
            result = 0;
            for (int i = 0; i < caseNum; i++)
            {
                int[] site = Array.ConvertAll(reader.ReadLine().Split(' '), int.Parse);
                int n = Math.Min(site[0], site[1]);
                int m = Math.Max(site[0], site[1]);
                result = Pacto(m) / (Pacto(n) * Pacto(m - n));
                writer.WriteLine(result);
            }
            reader.Close();
            writer.Flush();
        }

        static BigInteger Pacto(int n)
        {
            if (n <= 0)
            {
                return 1;
            }
            return n * Pacto(n - 1);
        }
    }
}
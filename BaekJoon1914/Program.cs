using System;
using System.IO;
using System.Numerics;

namespace BaekJoon1914
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            BigInteger i = (BigInteger) Math.Pow(2, n) - 1;
            writer.WriteLine(i);
            if (n <= 20)
            {
                Hanoi(n, 1, 3, 2);
            }
            writer.Flush();
            reader.Close();
        }

        static void Hanoi(int n, int start, int to, int via)
        {
            if (n == 1)
            {
                writer.WriteLine(start + " " + to);
                return;
            }
            Hanoi(n - 1, start, via, to);
            writer.WriteLine(start + " " + to);
            Hanoi(n - 1, via, to, start);
        }
    }
}
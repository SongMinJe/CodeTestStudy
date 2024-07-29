using System;
using System.IO;

namespace BaekJoon11050
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int[] inputs = Array.ConvertAll(reader.ReadLine().Split(' '), int.Parse);
            int n = inputs[0];
            int k = inputs[1];
            int result = Pacto(n) / (Pacto(n - k) * Pacto(k));
            writer.WriteLine(result);
            reader.Close();
            writer.Flush();
        }
        static int Pacto(int num)
        {
            if (num <= 1)
            {
                return 1;
            }
            return num * Pacto(num - 1);
        }
    }
}

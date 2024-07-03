using System;
using System.IO;

namespace BaekJoon2751
{
    internal class Program
    {
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            int[] inputs = new int[n];
            for (int i = 0; i < n; i++)
            {
                inputs[i] = int.Parse(reader.ReadLine());
            }
            Array.Sort(inputs);
            for (int i = 0; i < n; i++)
            {
                writer.WriteLine(inputs[i]);
            }
            writer.Flush();
            reader.Close();
        }
    }
}

using System;
using System.IO;


namespace BaekJoon2750
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            int[] input = new int[n];

            for (int i = 0; i < n; i++)
            {
                input[i] = int.Parse(reader.ReadLine());
            }
            Array.Sort(input);
            for (int i = 0; i < n; i++)
            {
                writer.WriteLine(input[i]);
            }
            writer.Flush();
            reader.Close();
        }
    }
}

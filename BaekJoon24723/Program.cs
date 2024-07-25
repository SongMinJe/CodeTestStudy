using System;
using System.IO;

namespace BaekJoon24723
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            writer.WriteLine(Math.Pow(2, n));
            reader.Close();
            writer.Flush();
        }
    }
}
using System;
using System.IO;

namespace BaekJoon10989
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            int[] inputs = new int[10001];

            for (int i = 0; i < n; i++)
            {
                inputs[int.Parse(reader.ReadLine())]++;
            }
            
            for (int i = 0; i < 10001; i++)
            {
                if(inputs[i] != 0)
                {
                    for (int j = 0; j < inputs[i]; j++)
                    {
                        writer.WriteLine(i);
                    }
                }
            }
            
            writer.Flush();
            reader.Close();
        }
    }
}
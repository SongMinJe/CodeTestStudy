using System;
using System.IO;
namespace BaekJoon2563
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static int result;
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            bool[,] arr = new bool[100, 100];
            result = 0;
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = false;
                }
            }
            for (int i = 0; i < n; i++)
            {
                string[] inputs = reader.ReadLine().Split(' ');
                int[] inputi = Array.ConvertAll(inputs, int.Parse);
                for (int j = inputi[0]; j < inputi[0] + 10; j++)
                {
                    for (int m = inputi[1]; m < inputi[1] + 10; m++)
                    {
                        arr[j, m] = true;
                    }
                }
            }
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    if (arr[i, j] == true)
                    {
                        result++;
                    }
                }
            }
            writer.WriteLine(result);

            reader.Close();
            writer.Flush();
        }
    }
}
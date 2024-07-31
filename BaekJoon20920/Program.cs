using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace BaekJoon20920
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int[] input = Array.ConvertAll(reader.ReadLine().Split(' '), int.Parse);
            Dictionary<string, int> dict = new Dictionary<string, int>();
            int n = input[0];
            int m = input[1];
            for (int i = 0; i < n; i++)
            {
                string word = reader.ReadLine();
                if (word.Length < m)
                {
                    continue;
                }
                dict.TryAdd(word, 0);

                dict[word]++;
            }

            var sorted = dict.OrderByDescending(x => x.Value).ThenByDescending(x => x.Key.Length).ThenBy(x => x.Key).ToDictionary(x => x.Key, x => x.Value);
            foreach (var w in sorted)
            {
                sb.AppendLine (w.Key);
            }
            writer.WriteLine(sb);
            reader.Close();
            writer.Flush();
        }
    }
}
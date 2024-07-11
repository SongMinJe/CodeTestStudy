using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace BaekJoon2805
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            string[] input = reader.ReadLine().Split();
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            int[] trees = Array.ConvertAll(reader.ReadLine().Split(), int.Parse); // 나무의 높이

            long start = 0;
            long end = trees.Max();
            //원하는 길이 찾기 위한 중간값
            //이 문제에서는 middle이 원하는 길이
            long middle = 0;
            long sum = 0;

            List<(long, long)> arr = new List<(long, long)>();

            while (true)
            {
                sum = 0;
                if (start > end)
                {
                    break;
                }

                middle = (start + end) / 2;

                for (int i = 0; i < n; i++)
                {
                    //잘라낼 나무 계산
                    if (trees[i] > middle)
                    {
                        sum += trees[i] - middle;
                    }
                }

                
                arr.Add((middle, sum));
                if (sum == m)
                {
                    break;
                }

                //범위 변경, 중간값 변경
                if (sum >= m)
                {
                    start = middle + 1;
                }
                else
                {
                    end = middle - 1;
                }

            }

            arr.Sort((a, b) => a.Item2.CompareTo(b.Item2));

            foreach (var value in arr)
            {
                if (value.Item2 >=m)
                {
                    writer.WriteLine(value.Item1);
                    break;
                }
            }

            writer.Close();
            reader.Close();
        }
    }
}
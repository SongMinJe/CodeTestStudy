using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace BaekJoon2805_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(new BufferedStream(Console.OpenStandardInput())))
            using (var writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput())))
            {
                var info = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                int n = info[0];
                int m = info[1];
                int[] trees = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                //이분탐색은 첫값과 끝값을 유동적으로 변환하기때문에 첫, 끝값 변수
                int start = 0;
                int end = trees.Max();
                int result = 0;

                //이진탐색 반복
                while (start <= end)
                {
                    //sum은 각 탐색마다 계산해야하기 때문에 초기화
                    long sum = 0;
                    //중간값
                    int middle = (start + end) / 2;
                    foreach (int tree in trees)
                    {
                        if (tree > middle)
                        {
                            sum += tree - middle;
                        }
                    }
                    if (sum >= m)
                    {
                        result = middle;
                        start = middle + 1;
                    }
                    else
                    {
                        end = middle - 1;
                    }
                }
                writer.WriteLine(result);
            }
        }
    }
}
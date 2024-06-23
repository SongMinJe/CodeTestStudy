using System;
using System.Collections.Generic;
using System.Linq;

namespace BaekJoon1026
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //s = a1 * b1 + a2 * b2 +....
            //a를 재배열하여 최소값을 구하라
            //a를 오름차순으로 정렬하여
            //a와 b의 최대값에 곱해주고 더해서 결과도출
            int n = int.Parse(Console.ReadLine());
            List<int> a_List = new List<int>();
            List<int> b_List = new List<int>();
            string[] a = Console.ReadLine().Split(' ');
            string[] b = Console.ReadLine().Split(' ');
            int result = 0;
            
            for (int i = 0; i < n; i++)
            {
                a_List.Add(int.Parse(a[i]));
                b_List.Add(int.Parse(b[i]));
            }
            a_List.Sort();
            for (int i = 0; i < n; i++)
            {
                result += a_List[i] * b_List.Max();
                b_List.Remove(b_List.Max());
            }
            Console.WriteLine(result);
        }
    }
}

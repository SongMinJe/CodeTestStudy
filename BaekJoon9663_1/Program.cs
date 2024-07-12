using System;
using System.IO;

namespace BaekJoon9663_1
{
    internal class Program
    {
        public static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        public static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        //입력값
        static int n;
        static int[] ans;
        static int result = 0;
        static void DFS(int cnt)
        {
            if (cnt == n)
            {
                result++;
                return;
            }
            for (int i = 0; i < n; i++)
            {
                ans[cnt] = i;
                if (Able(cnt))
                {
                    DFS(cnt + 1);
                }
            }
        }

        static bool Able(int cnt)
        {
            for (int i = 0; i < cnt; i++)
            {
                if (ans[cnt] == ans[i])
                {
                    return false;
                }
                else if (Math.Abs(cnt - i) == Math.Abs(ans[cnt] - ans[i]))
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            n = int.Parse(reader.ReadLine());
            ans = new int[n];
            result = 0;
            DFS(0);
            writer.WriteLine(result);

            writer.Flush();
            reader.Close();
        }
    }
}
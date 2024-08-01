using System;
using System.IO;

namespace BaekJoon9663_2
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static int n;
        static int[] ans;
        static int result;
        static void DFS(int cnt)
        {
            // DFS탈출 // 퀸을 다 놓는 한 케이스 완성
            // 퀸을 n만큼 다 놓고도 서로 공격할수 없을때
            if (cnt == n)
            {
                // 성공케이스 1 추가
                result++;
                return;
            }
            // 퀸 배치 경우의 수 세기
            for (int i = 0; i < n; i++)
            {
                // 퀸 배치
                // cnt행과 i열에 배치
                ans[cnt] = i;
                // 퀸을 놓을 수 있는지
                if (Queen(cnt))
                {
                    // DFS(cnt + 1) 재귀
                    DFS(cnt + 1);
                }
            }
        }

        static bool Queen(int cnt)
        {
            for (int i = 0; i < cnt; i++)
            {
                // 행 비교
                // 전에 배치한 퀸 기준으로
                // 다음에 놓은 퀸이 같은 행에 있는지
                if (ans[cnt] == ans[i])
                {
                    return false;
                }
                // 대각선 비교
                // 전에 배치한 퀸의 행과 열의 차 == 다음에 배치한 퀸의 행과 열의 차
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
            reader.Close();
            writer.Flush();
        }
    }
}
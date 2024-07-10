using System;
using System.IO;

namespace BaekJoon10819_2
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        //주어진 숫자
        static int[] arr;
        //각 노드당 방문 여부
        static bool[] visit;
        //재귀중 모든 경우의 수를 판별하기 위해 선정된 n개의 숫자를 담을 배열
        static int[] ans;
        static int result = 0;
        static int n;
        static void DFS(int cnt)
        {
            //재귀 탈출 조건
            if (cnt == n)
            {
                //최대값을 판별하기 위한 조건에서의 합
                int sum = 0;
                //역대 최대값 선정
                for (int i = 0; i < n - 1; i++)
                {
                    //문제 조건
                    //절대값(i - (i + 1))합의 최대값
                    sum += Math.Abs(ans[i] - ans[i + 1]);
                }
                //전역변수를 통해 다음 재귀로 넘길 최대값
                //다음 재귀시 비교하여 최대값을 다시 넣어준다.
                result = Math.Max(result, sum);
                return;
            }

            //방문한 노드를 체크하며 모든 경우의 수를 탐색
            for (int i = 0; i < n; i++)
            {
                //방문한 노드니?
                if (!visit[i])
                {
                    //케이스 추가를 위한 배열 삽입
                    ans[cnt] = arr[i];
                    //방문 했음
                    visit[i] = true;
                    //재귀
                    //카운트를 추가해주며 n과 같아지면 문제 조건 비교
                    DFS(cnt + 1);
                    //조건 비교가 끝나 다음 케이스 추가를 위한 방문 여부 초기화
                    visit[i] = false;
                }
            }
        }
        static void Main(string[] args)
        {
            n = int.Parse(reader.ReadLine());
            string[] inputs = reader.ReadLine().Split(' ');
            arr = new int[n];
            ans = new int[n];
            visit = new bool[n];
            result = 0;
            for (int i = 0; i < inputs.Length; i++)
            {
                arr[i] = int.Parse(inputs[i]);
            }
            DFS(0);
            writer.WriteLine(result);
            reader.Close();
            writer.Flush();
        }
    }
}
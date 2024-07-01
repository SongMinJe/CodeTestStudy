using System;
using System.IO;

namespace BaekJoon9663
{
    internal class Program
    {
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));

        //퀸의 갈수있는 칸이 겹치지 않으면 좋겠다.
        //퀸의 대각선과, 같은 열이 겹치면 안된다.
        //퀸은 행,열,대각선으로 움직이니 대각선에도 있으면 안된다.
        //arr[n] == arr[i] 면, 같은 행으로 겹친다
        //행과 열을 표현할 배열 arr, 입력받은 n, 행을 표현할 depth, ref로 answer입력
        static void BackTracking(int[] arr, int n, int depth, ref int answer)
        {
            //depth가 n과 같을때 return하여 돌아가자
            //한가지 찾았으니 answer에 1더해준다.
            if (n == depth)
            {
                ++answer;
                return;
            }
            //모든 퀸의 갯수만큼 반복하자
            for (int i = 0; i < n; i++)
            {
                //행에 열을 기록하자
                arr[depth] = i;
                //겹치지 않는다면 재귀로 depth + 1만큼 깊숙히 들어가자
                if (IsValid(arr, depth) == true)
                {
                    BackTracking(arr, n, depth + 1, ref answer);
                }
            }
        }

        //겹치는지 판별할 bool 메서드
        //판별하기 위해서는 행과 열을 비교할 요소를 가져오자
        //행 : arr, 열 : depth가 필요하다.
        static bool IsValid(int[] arr, int depth)
        {
            //깊이 만큼 반복하여 모든 행들을 비교
            for (int i = 0; i < depth; ++i)
            {
                //각 행의 열이 겹치니?
                if (arr[i] == arr[depth])
                {
                    return false;
                }
                //대각선이 겹치니?
                //절대값(x1 - x2) = 절대값(y1 - y2)가 전부 같다.
                if (Math.Abs(arr[i] - arr[depth]) == Math.Abs(i - depth))
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            int answer = 0;
            int n = int.Parse(reader.ReadLine());
            var arr = new int[n];
            //첫 depth (행)은 0이다.
            BackTracking(arr, n, 0, ref answer);
            writer.WriteLine(answer);
            writer.Flush();
            reader.Close();
        }
    }
}

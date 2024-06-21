using System;

namespace 백준
{
    internal class Program
    {
        //회의가 겹치지 않는 최소 갯수를 구하고싶다.
        //1. 회의 케이스의 수 n을 받아서 저장
        //2. int,int 튜플 time을 n개 만큼 저장
        //   시작 시간과 끝 시간중에 어떤것을 비교하고 옮기더라도 두 요소가 같이 움직여야 하므로
        //3. 회의 시작과 끝 시간들을 받아서 튜플에 저장하는 for문 n개 까지 저장
        //       공백을 기준으로 나눠 저장을 위해 split
        //4. 끝 시간을 기준으로 오름차순 정렬한다.
        //   for문으로 비교했을 때, 순차적으로 비교해야 편하다.
        //   끝 시간으로 오름차순해야 다음 회의의 시작 시간과 비교했을때, 겹치는지 판별이 가능
        //   튜플의 element들이 같은 숫자로 겹치는 경우를 비교 하며 정렬
        //   함수를 만들어 그 함수를 람다식으로 정렬 중에 실행
        //      끝 시간이 겹치는 경우 시작 시간이 빠른 순서로 정렬
        //      끝 시간이 겹치지 않는 경우 끝 시간이 빠른 순서로 정렬
        //5. 전 회의의 끝 시간과 현재 회의의 시작 시간을 비교
        //   n개 만큼 비교하며 반복해야 하므로 for문 n개까지 비교
        //   전 회의의 끝 시간이 현재 회의의 시작 시간보다 적다면 겹치지 않는다.
        //      - 다음 회의의 시간이 겹치는지 판별을 위해 현재 끝시간을 전 회의의 끝 시간에 저장
        //          - 따로 변수를 만들어 저장해서 비교하면 편하다
        //   결과케이스에 1 더해준다.
        //6. 결과를 출력한다.
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            (int start, int end)[] time = new (int, int)[n];
            int result = 0;

            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                time[i] = (int.Parse(input[0]), int.Parse(input[1]));
            }

            Array.Sort(time, (x, y) => Compare(x, y));

            int endTemp = 0;

            for(int i = 0; i < n; i++)
            {
                if (endTemp < time[i].start )
                {
                    endTemp = time[i].end;
                    result++;
                }
            }

            Console.Write(result);

            int Compare((int start, int end)x, (int start, int end) y)
            {
                if (x.end == y.end)
                {
                    return (x.start < y.start) ? -1 : 1;
                }
                else
                {
                    return (x.end < y.end) ? -1 : 1;
                }
            }
        }
    }
}

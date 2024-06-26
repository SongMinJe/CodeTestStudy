using System;

namespace BaekJoon2720
{
    internal class Program
    {
        //n개의 케이스를 받는다
        //동전의 종류를 배열에 담기
        //결과 배열 만들어 0담기
        //n번 반복
        //한 케이스를 받고
        //동전 종류수만큼 반복
        //케이스 > coin[j] 이면
        //케이스 -= coins[j];
        //결과++
        //결과 출력
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] coins = { 25, 10, 5, 1 };
            int[] results = { 0, 0, 0, 0 };
            int[] _case = new int[n];
            for (int i = 0; i < n; i++)
            {
                _case[i] = int.Parse(Console.ReadLine());
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < coins.Length; j++)
                {
                    while (_case[i] >= coins[j])
                    {
                        _case[i] -= coins[j];
                        results[j]++;
                    }
                    Console.Write(results[j] + " ");
                    results[j] = 0;
                }
                Console.WriteLine();
            }
        }
    }
}

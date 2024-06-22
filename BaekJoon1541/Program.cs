using System;
using System.Linq;

namespace 백준
{
    internal class Program
    {
        //주어지는 식에 괄호를 적절히 쳐서 최소값을 만들고 싶다
        //최소값이 되려면 - 뒤부터 다음 -가 나오기 전까지 괄호를 치면 최소값이 될 것이다.
        //string[]으로 받고 -로 split
        //string배열 내부에 +가 있나? >> 있으면 덧셈계산
        //for문 돌면서 뺄셈 계산

        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] str1;
            int result = 0;
            if (input.Contains('-'))
            {
                str1 = input.Split('-');
                int[] calc = new int[str1.Length];
                for (int i = 0; i < str1.Length; i++)
                {
                    if (str1[i].Contains('+'))
                    {
                        string[] str2 = str1[i].Split('+');
                        int sum = 0;
                        for (int j = 0; j < str2.Length; j++)
                        {
                            sum += int.Parse(str2[j]);
                        }
                        calc[i] = sum;
                    }
                    else
                    {
                        calc[i] = int.Parse(str1[i]);
                    }
                }
                for (int i = 1; i < calc.Length; i++)
                {
                    result -= calc[i];
                }
                Console.WriteLine(result + calc[0]);
            }
            else
            {
                str1 = input.Split('+');
                foreach (string st in str1)
                {
                    result += int.Parse(st);
                }
                Console.WriteLine(result);
            }
        }
    }
}

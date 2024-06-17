using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon2839
{
    internal class BaekJoon2839
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int result = 0;

            //그리디
            //한번씩 되는지 여부 판단
            //5봉지로 됨? 안되면 3봉지 하나 덜기
            //3봉지 하나 추가
            while (n > 0)
            {
                if (n % 5 == 0)
                {
                    result += n / 5;
                    break;
                }

                n -= 3;
                result++;
            }
            //나누어 떨어지는 조함이 없을때
            //그리디가 끝나고 남는 값이 0보다 작으면
            //깔끔하게 담을 방법이 없다.
            if (n < 0)
            {
                result = -1;
            }
            Console.Write(result);
        }
    }
}
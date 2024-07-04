using System;
using System.IO;

namespace BaekJoon10989
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            //입력받는 값은 10000이하의 자연수
            int[] inputs = new int[10001];
            for (int i = 0; i < inputs.Length; i++)
            {
                inputs[i] = 0;
            }
            //최대 1천만개의 숫자를 입력받은 순서대로
            //메모리가 제한되어 있기에 천만개의 인덱스는 무리.
            //대신 입력받은 숫자 value를 인덱스 삼아
            //그 인덱스에 1씩더하여 그 숫자가 몇번 들어왔는지 체크
            for (int i = 0; i < n; i++)
            {
                inputs[int.Parse(reader.ReadLine())]++;
            }

            //어차피 인덱스는 정렬되어있다.
            //따로 정렬 필요 없이 인덱스 순서대로
            //인덱스의 value 만큼 반복하여 출력하면 정렬된 결과를 얻는다.
            for (int i = 0; i < 10001; i++)
            {
                for (int j = 0; j < inputs[i]; j++)
                {
                    writer.WriteLine(i);
                }
            }
            
            writer.Flush();
            reader.Close();
        }
    }
}
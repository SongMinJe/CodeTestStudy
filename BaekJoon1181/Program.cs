using System;
using System.Collections.Generic;
using System.IO;

namespace BaekJoon1181
{
    internal class Program
    {
        static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
        static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
        static void Main(string[] args)
        {
            int n = int.Parse(reader.ReadLine());
            // 중복 제거 리스트 HashSet
            HashSet<string> inputs = new HashSet<string>();
            // 삽입
            for (int i = 0; i < n; i++)
            {
                inputs.Add(reader.ReadLine());
            }
            // 정렬을 위한 List
            List<string> sortedInputs = new List<string>(inputs);
            // 여러개의 조건을 통해 정렬하기 위해 람다식 활용
            // x는 비교되는 글자
            // y는 비교하는 글자
            // .Sort는 퀵정렬
            // 여기에서는 람다의 리턴이 0이라면 그대로,
            // 음수면 x가 y보다 앞쪽,
            // 양수면 뒤쪽에 위치해야한다.
            sortedInputs.Sort((x, y) =>
            {
                //글자 수가 같을 때
                if (x.Length == y.Length)
                {
                    //사전순으로 정렬
                    return string.Compare(x, y);
                }
                //글자 수가 다를 때
                else
                {
                    //음수, 0, 양수중 하나를 리턴하여 y값이 위치해야 할 정보 리턴
                    return x.Length.CompareTo(y.Length);
                }
            });
            //출력
            foreach(var word in sortedInputs)
            {
                writer.WriteLine(word);
            }
            //할당 해제
            writer.Flush();
            reader.Close();
        }
    }
}
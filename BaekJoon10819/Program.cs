using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Program
{
    static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    static int MaxDifference(List<int> nums)
    {
        bool[] visited = new bool[nums.Count];
        int maxValue = int.MinValue;
        List<int> current = new List<int>();

        void DFS()
        {
            if (current.Count == nums.Count)
            {
                int currentValue = 0;
                for (int i = 0; i < current.Count - 1; i++)
                {
                    
                    currentValue += Math.Abs(current[i] - current[i + 1]);
                }
                maxValue = Math.Max(maxValue, currentValue);
                return;
            }

            for (int i = 0; i < nums.Count; i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    current.Add(nums[i]);
                    DFS();
                    current.RemoveAt(current.Count - 1);
                    visited[i] = false;
                }
            }
            
        }
        DFS();
        
        return maxValue;
    }

    static void Main()
    {
        // 주어진 숫자 리스트
        int n = int.Parse(reader.ReadLine());
        List<int> numbers = new List<int>(n);
        string[] inputs = reader.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            numbers.Add(int.Parse(inputs[i]));
        }
        int maxDifference = MaxDifference(numbers);

        // 최대값 출력
        writer.WriteLine(maxDifference);

        reader.Close();
        writer.Flush();
    }
}

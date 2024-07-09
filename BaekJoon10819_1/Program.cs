using System;
using System.IO;

class Program
{
    static StreamReader reader = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
    static StreamWriter writer = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
    public static int n;
    public static int[] arr;
    public static int[] ans;
    public static bool[] visit;
    public static int result;
    public static void DFS(int cnt)
    {
        if (cnt == n)
        {
            int sum = 0;
            for (int i = 0; i < n - 1; i++)
            {
                sum += Math.Abs(ans[i] - ans[i + 1]);
            }
            result = Math.Max(result, sum);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                ans[cnt] = arr[i];
                visit[i] = true;
                DFS(cnt + 1);
                visit[i] = false;
            }
        }
    }
    public static void Main()
    {
        n = int.Parse(reader.ReadLine());
        string[] inputs = reader.ReadLine().Split(' ');
        arr = new int[n];
        ans = new int[n];
        visit = new bool[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(inputs[i]);
        }
        DFS(0);
        writer.WriteLine(result);
        writer.Flush();
        reader.Close();
    }
}
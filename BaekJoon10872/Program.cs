using System;

namespace BaekJoon10872
{
    internal class Program
    {
        
        static int Pacto(int n)
        {
            int result = 1;
            if (n > 1)
            {
                result = n * Pacto(n - 1);
                return result;
            }
            else
            {
                return result;
            }
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(Pacto(n));
        }
    }
}

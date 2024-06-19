using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon11399
{
    internal class BaekJoon11399
    {
        static void Main(string[] args)
        {
            string n = Console.ReadLine();
            string[] ps = Console.ReadLine().Split(' ');
            List<int> pi = new List<int>();
            int sum = 0;
            int result = 0;

            foreach (string s in ps) 
            {
                pi.Add(int.Parse(s));
            }

            pi.Sort();

            for (int i = 1; i < int.Parse(n); i++)
            {
                sum += pi[i - 1];
                result += sum + pi[i];
            }

            Console.Write(result + pi[0]);
        }
    }
}

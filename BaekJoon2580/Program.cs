using System;
using System.IO;
using System.Linq;

namespace BaekJoon2580
{
    class Program
    {
        static int[,] board = new int[9, 9];
        static StreamReader reader = new StreamReader(Console.OpenStandardInput());
        static StreamWriter writer = new StreamWriter(Console.OpenStandardOutput());

        static void Main()
        {
            for (int i = 0; i < 9; i++)
            {
                string[] line = reader.ReadLine().Split(' ');
                for (int j = 0; j < 9; j++)
                {
                    board[i, j] = int.Parse(line[j]);
                }
            }

            Solve();

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    writer.Write(board[i, j]);
                    if (j < 8) writer.Write(" ");
                }
                writer.WriteLine();
            }

            reader.Close();
            writer.Flush();
        }

        static bool Solve()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (board[i, j] == 0)
                    {
                        for (int num = 1; num <= 9; num++)
                        {
                            //숫자 체크
                            if (IsValid(i, j, num))
                            {
                                //없으면 삽입
                                board[i, j] = num;

                                //풀었음?
                                if (Solve())
                                {
                                    return true;
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        static bool IsValid(int row, int col, int num)
        {
            //행,열 검사
            for (int x = 0; x < 9; x++)
            {
                if (board[row, x] == num || board[x, col] == num)
                {
                    return false;
                }
            }

            //3 * 3 검사
            int boxRow = row - row % 3;
            int boxCol = col - col % 3;

            for (int i = boxRow; i < boxRow + 3; i++)
            {
                for (int j = boxCol; j < boxCol + 3; j++)
                {
                    if (board[i, j] == num)
                    {
                        return false;
                    }
                }
            }

            return true;
        }
    }
}
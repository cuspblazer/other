using System;

namespace StringSplitPyramid
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Zadejte vstupní řetězec: ");
            string retezec = Console.ReadLine();
            string[] rozdeleny_retezec = retezec.Split(" ");
            
            for (int i = rozdeleny_retezec.Length; i > 0; i--)
            {
                for (int j  = 0; j < i; j++)
                {
                    Console.Write(rozdeleny_retezec[j]);
                    Console.Write(" ");
                }
                Console.WriteLine();
            }
        }
    }
}

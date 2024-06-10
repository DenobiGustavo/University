using System;
using System.IO;

namespace Translator
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            if (args.Length == 0)
            {
                Console.WriteLine("Please provide the path to the source file.");
                return;
            }

            var path = args[0];

            if (!File.Exists(path))
            {
                Console.WriteLine($"The file {path} does not exist.");
                return;
            }

            var symbolTable = new SymbolTable();
            using var reader = new StreamReader(path);
            var lexer = new Lexer(reader, symbolTable);
            var parser
        }
    }
}
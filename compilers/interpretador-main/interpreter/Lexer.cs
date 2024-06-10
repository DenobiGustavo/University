using System;
using System.IO;
using System.Text;

namespace Translator
{
    public class Lexer
    {
        public int Line { get; private set; }
        public int Column { get; private set; }
        
        private char? _currentChar;
        private readonly StreamReader _reader;
        private readonly SymbolTable _symbolTable;

        public Lexer(StreamReader reader, SymbolTable symbolTable)
        {
            _reader = reader;
            _symbolTable = symbolTable;
            Line = 1;
            Column = 1;
            _currentChar = NextChar();
        }

        private char NextChar()
        {
            Column++;
            if (_reader.EndOfStream)
                return '\0';
            return (char)_reader.Read();
        }

        public Token GetNextToken()
        {
            while (_currentChar.HasValue && char.IsWhiteSpace(_currentChar.Value))
            {
                if (_currentChar == '\n')
                {
                    Line++;
                    Column = 1;
                }
                _currentChar = NextChar();
            }

            if (!_currentChar.HasValue)
                return new Token(TokenType.EOF);

            switch (_currentChar)
            {
                case '+': _currentChar = NextChar(); return new Token(TokenType.PLUS);
                case '-': _currentChar = NextChar(); return new Token(TokenType.MINUS);
                case '*': _currentChar = NextChar(); return new Token(TokenType.TIMES);
                case '/': _currentChar = NextChar(); return new Token(TokenType.DIVIDE);
                case '(': _currentChar = NextChar(); return new Token(TokenType.LPAREN);
                case ')': _currentChar = NextChar(); return new Token(TokenType.RPAREN);
                case '=': _currentChar = NextChar(); return new Token(TokenType.ASSIGN);
                case '\n': _currentChar = NextChar(); return new Token(TokenType.EOL);
            }

            if (char.IsDigit(_currentChar.Value))
            {
                var number = new StringBuilder();
                while (_currentChar.HasValue && char.IsDigit(_currentChar.Value))
                {
                    number.Append(_currentChar);
                    _currentChar = NextChar();
                }
                return new Token(TokenType.NUMBER, int.Parse(number.ToString()));
            }

            if (_currentChar == '#')
            {
                var identifier = new StringBuilder();
                _currentChar = NextChar();
                while (_currentChar.HasValue && char.IsLetter(_currentChar.Value))
                {
                    identifier.Append(_currentChar);
                    _currentChar = NextChar();
                }
                var symbol = _symbolTable.Insert(identifier.ToString());
                return new Token(TokenType.VAR, symbol);
            }

            if (_currentChar == 'g')
            {
                if (TestKeyword("et"))
                    return new Token(TokenType.INPUT);
            }

            if (_currentChar == 's')
            {
                if (TestKeyword("how"))
                    return new Token(TokenType.OUTPUT);
            }

            return new Token(TokenType.ERROR);
        }

        private bool TestKeyword(string suffix)
        {
            foreach (var c in suffix)
            {
                _currentChar = NextChar();
                if (!_currentChar.HasValue || _currentChar != c)
                    return false;
            }
            _currentChar = NextChar();
            return true;
        }
    }
}

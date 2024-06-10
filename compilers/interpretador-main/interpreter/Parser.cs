using System;

namespace Translator
{
    public class Parser
    {
        private readonly Lexer _lexer;
        private Token _currentToken;
        private readonly SymbolTable _symbolTable;

        public Parser(Lexer lexer, SymbolTable symbolTable)
        {
            _lexer = lexer;
            _symbolTable = symbolTable;
            _currentToken = _lexer.GetNextToken();
        }

        private void Eat(TokenType tokenType)
        {
            if (_currentToken.Type == tokenType)
            {
                _currentToken = _lexer.GetNextToken();
            }
            else
            {
                throw new Exception($"Syntax error: expected {tokenType}, found {_currentToken.Type}");
            }
        }

        public void Parse()
        {
            Program();
        }

        private void Program()
        {
            while (_currentToken.Type != TokenType.EOF)
            {
                Statement();
            }
        }

        private void Statement()
        {
            switch (_currentToken.Type)
            {
                case TokenType.INPUT:
                    InputStatement();
                    break;
                case TokenType.OUTPUT:
                    OutputStatement();
                    break;
                case TokenType.VAR:
                    AssignmentStatement();
                    break;
                case TokenType.EOL:
                    Eat(TokenType.EOL);
                    break;
                default:
                    throw new Exception($"Syntax error: unexpected token {_currentToken.Type}");
            }
        }

        private void InputStatement()
        {
            Eat(TokenType.INPUT);
            var variableToken = _currentToken;
            Eat(TokenType.VAR);
            Console.WriteLine($"Enter value for {variableToken.Value}: ");
            var value = double.Parse(Console.ReadLine() ?? throw new InvalidOperationException());
            _symbolTable.Update(variableToken.Value, value);
        }

        private void OutputStatement()
        {
            Eat(TokenType.OUTPUT);
            var variableToken = _currentToken;
            Eat(TokenType.VAR);
            var value = _symbolTable.Get(variableToken.Value);
            Console.WriteLine(value);
        }

        private void AssignmentStatement()
        {
            var variableToken = _currentToken;
            Eat(TokenType.VAR);
            Eat(TokenType.ASSIGN);
            var value = Expression();
            _symbolTable.Update(variableToken.Value, value);
        }

        private double Expression()
        {
            var result = Term();
            while (_currentToken.Type == TokenType.PLUS || _currentToken.Type == TokenType.MINUS)
            {
                if (_currentToken.Type == TokenType.PLUS)
                {
                    Eat(TokenType.PLUS);
                    result += Term();
                }
                else if (_currentToken.Type == TokenType.MINUS)
                {
                    Eat(TokenType.MINUS);
                    result -= Term();
                }
            }
            return result;
        }

        private double Term()
        {
            var result = Factor();
            while (_currentToken.Type == TokenType.TIMES || _currentToken.Type == TokenType.DIVIDE)
            {
                if (_currentToken.Type == TokenType.TIMES)
                {
                    Eat(TokenType.TIMES);
                    result *= Factor();
                }
                else if (_currentToken.Type == TokenType.DIVIDE)
                {
                    Eat(TokenType.DIVIDE);
                    result /= Factor();
                }
            }
            return result;
        }

        private double Factor()
        {
            var token = _currentToken;
            if (token.Type == TokenType.NUMBER)
            {
                Eat(TokenType.NUMBER);
                return (int)token.Value;
            }
            else if (token.Type == TokenType.VAR)
            {
                Eat(TokenType.VAR);
                return _symbolTable.Get(token.Value);
            }
            else if (token.Type == TokenType.LPAREN)
            {
                Eat(TokenType.LPAREN);
                var result = Expression();
                Eat(TokenType.RPAREN);
                return result;
            }
            else
            {
                throw new Exception($"Syntax error: unexpected token {token.Type}");
            }
        }
    }
}

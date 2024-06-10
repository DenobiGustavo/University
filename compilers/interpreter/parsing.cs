using System;
using System.Collections.Generic;

public abstract class AST
{
}

public class BinOp : AST
{
    public AST Left { get; }
    public Token Op { get; }
    public AST Right { get; }

    public BinOp(AST left, Token op, AST right)
    {
        Left = left;
        Op = op;
        Right = right;
    }
}

public class Num : AST
{
    public Token Token { get; }
    public string Value { get; }

    public Num(Token token)
    {
        Token = token;
        Value = token.Value;
    }
}

public class Var : AST
{
    public Token Token { get; }
    public string Value { get; }

    public Var(Token token)
    {
        Token = token;
        Value = token.Value;
    }
}

public class Assign : AST
{
    public Var Left { get; }
    public Token Op { get; }
    public AST Right { get; }

    public Assign(Var left, Token op, AST right)
    {
        Left = left;
        Op = op;
        Right = right;
    }
}

public class Parser
{
    private List<Token> _tokens;
    private int _pos;
    private Token _currentToken;

    public Parser(List<Token> tokens)
    {
        _tokens = tokens;
        _pos = 0;
        _currentToken = _tokens[_pos];
    }

    private void Error()
    {
        throw new Exception("Invalid syntax");
    }

    private void Eat(TokenType tokenType)
    {
        if (_currentToken.Type == tokenType)
        {
            _currentToken = _tokens[++_pos];
        }
        else
        {
            Error();
        }
    }

    private AST Factor()
    {
        var token = _currentToken;

        if (token.Type == TokenType.Number)
        {
            Eat(TokenType.Number);
            return new Num(token);
        }
        else if (token.Type == TokenType.Identifier)
        {
            Eat(TokenType.Identifier);
            return new Var(token);
        }
        else if (token.Type == TokenType.LeftParen)
        {
            Eat(TokenType.LeftParen);
            var node = Expr();
            Eat(TokenType.RightParen);
            return node;
        }

        Error();
        return null;
    }

    private AST Term()
    {
        var node = Factor();

        while (_currentToken.Type == TokenType.Multiply || _currentToken.Type == TokenType.Divide)
        {
            var token = _currentToken;
            if (token.Type == TokenType.Multiply)
            {
                Eat(TokenType.Multiply);
            }
            else if (token.Type == TokenType.Divide)
            {
                Eat(TokenType.Divide);
            }

            node = new BinOp(node, token, Factor());
        }

        return node;
    }

    private AST Expr()
    {
        var node = Term();

        while (_currentToken.Type == TokenType.Plus || _currentToken.Type == TokenType.Minus)
        {
            var token = _currentToken;
            if (token.Type == TokenType.Plus)
            {
                Eat(TokenType.Plus);
            }
            else if (token.Type == TokenType.Minus)
            {
                Eat(TokenType.Minus);
            }

            node = new BinOp(node, token, Term());
        }

        return node;
    }

    public AST Parse()
    {
        if (_currentToken.Type == TokenType.Identifier)
        {
            var left = new Var(_currentToken);
            Eat(TokenType.Identifier);
            var op = _currentToken;
            Eat(TokenType.Assign);
            var right = Expr();
            return new Assign(left, op, right);
        }

        return Expr();
    }
}

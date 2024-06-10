using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public enum TokenType
{
    Number,
    Identifier,
    Plus,
    Minus,
    Multiply,
    Divide,
    Assign,
    LeftParen,
    RightParen,
    EndOfFile
}

public class Token
{
    public TokenType Type { get; }
    public string Value { get; }

    public Token(TokenType type, string value)
    {
        Type = type;
        Value = value;
    }

    public override string ToString()
    {
        return $"Token({Type}, {Value})";
    }
}

public class Lexer
{
    private string _text;
    private int _pos;
    private char _currentChar;

    private Dictionary<string, TokenType> _keywords = new Dictionary<string, TokenType>
    {
        { "+", TokenType.Plus },
        { "-", TokenType.Minus },
        { "*", TokenType.Multiply },
        { "/", TokenType.Divide },
        { "=", TokenType.Assign },
        { "(", TokenType.LeftParen },
        { ")", TokenType.RightParen }
    };

    public Lexer(string text)
    {
        _text = text;
        _pos = 0;
        _currentChar = _text[_pos];
    }

    private void Advance()
    {
        _pos++;
        if (_pos > _text.Length - 1)
        {
            _currentChar = '\0';
        }
        else
        {
            _currentChar = _text[_pos];
        }
    }

    private void SkipWhitespace()
    {
        while (_currentChar != '\0' && char.IsWhiteSpace(_currentChar))
        {
            Advance();
        }
    }

    private string Integer()
    {
        var result = string.Empty;
        while (_currentChar != '\0' && char.IsDigit(_currentChar))
        {
            result += _currentChar;
            Advance();
        }
        return result;
    }

    private string Identifier()
    {
        var result = string.Empty;
        while (currentChar != '\0' && (char.IsLetterOrDigit(_currentChar) || _currentChar == ''))
        {
            result += _currentChar;
            Advance();
        }
        return result;
    }

    public List<Token> GetTokens()
    {
        var tokens = new List<Token>();

        while (_currentChar != '\0')
        {
            if (char.IsWhiteSpace(_currentChar))
            {
                SkipWhitespace();
                continue;
            }

            if (char.IsDigit(_currentChar))
            {
                tokens.Add(new Token(TokenType.Number, Integer()));
                continue;
            }

            if (char.IsLetter(_currentChar))
            {
                tokens.Add(new Token(TokenType.Identifier, Identifier()));
                continue;
            }

            if (_keywords.ContainsKey(_currentChar.ToString()))
            {
                tokens.Add(new Token(_keywords[_currentChar.ToString()], _currentChar.ToString()));
                Advance();
                continue;
            }

            throw new Exception($"Unexpected character: {_currentChar}");
        }

        tokens.Add(new Token(TokenType.EndOfFile, null));
        return tokens;
    }
}

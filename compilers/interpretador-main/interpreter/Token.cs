namespace Translator
{
    public class Token
    {
        public TokenType Type { get; }
        public object Value { get; }

        public Token(TokenType type, object value = null)
        {
            Type = type;
            Value = value;
        }
    }
}

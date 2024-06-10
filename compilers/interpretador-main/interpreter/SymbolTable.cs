using System.Collections.Generic;

namespace Translator
{
    public class SymbolTable
    {
        private readonly Dictionary<string, double> _table = new();

        public string Insert(string symbol)
        {
            if (!_table.ContainsKey(symbol))
            {
                _table[symbol] = 0;
            }
            return symbol;
        }

        public void Update(string symbol, double value)
        {
            _table[symbol] = value;
        }

        public double Get(string symbol)
        {
            return _table.TryGetValue(symbol, out var value) ? value : 0;
        }
    }
}

namespace Translator{

    public class TableEntry{

        public ETokenType Type{ get; set;}
        public string Name {get; set;}
        public double? Value {get; set;}

        public TableEntry(ETokenType type, string name, double? value=null){
            
            this.Type = type;
            this.Name = name;
            this.Value = value;

        }

    }

}